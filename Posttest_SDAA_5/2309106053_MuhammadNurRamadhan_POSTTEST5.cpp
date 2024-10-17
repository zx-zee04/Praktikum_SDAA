#include <iostream>
#include <string>
#include <limits>
#include <iomanip>

using namespace std;

struct Karyawan {
    int id;
    string nama;
    int umur;
    string jabatan;
    int gaji;
    Karyawan* next;
};

int inputInteger() {
    int nilai;
    while (true) {
        cin >> nilai;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Input tidak valid. Masukkan angka yang benar: ";
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return nilai;
        }
    }
}

void pushKaryawan(Karyawan* &top) {
    Karyawan* baru = new Karyawan;
    cout << "Masukkan ID Karyawan: ";
    baru->id = inputInteger();
    
    cin.ignore(); 
    cout << "Masukkan Nama Karyawan: ";
    getline(cin, baru->nama);
    
    cout << "Masukkan Umur Karyawan: ";
    baru->umur = inputInteger();
    
    cout << "Masukkan Jabatan Karyawan: ";
    getline(cin, baru->jabatan);

    cout << "Masukkan Gaji Karyawan: ";
    baru->gaji = inputInteger();
    
    baru->next = top;
    top = baru;
    cout << "Karyawan berhasil ditambahkan ke Stack!\n";
}

void tampilkanStack(Karyawan* top) {
    if (top == nullptr) {
        cout << "Stack kosong.\n";
        return;
    }

    cout << left << setw(5) << "ID" 
         << setw(20) << "Nama" 
         << setw(10) << "Umur" 
         << setw(20) << "Jabatan" 
         << setw(15) << "Gaji" << endl;
    cout << setfill('=') << setw(70) << "=" << setfill(' ') << endl;

    Karyawan* temp = top;
    while (temp != nullptr) {
        cout << left << setw(5) << temp->id 
             << setw(20) << temp->nama 
             << setw(10) << temp->umur 
             << setw(20) << temp->jabatan
             << setw(15) << temp->gaji << endl;
        temp = temp->next;
    }
}

void updateKaryawan(Karyawan* head) {
    if (head == nullptr) {
        cout << "Tidak ada data karyawan.\n";
        return;
    }

    int idCari;
    cout << "Masukkan ID Karyawan yang ingin diperbarui: ";
    idCari = inputInteger();

    Karyawan* temp = head;
    while (temp != nullptr) {
        if (temp->id == idCari) {
            cin.ignore();
            cout << "Masukkan nama baru: ";
            getline(cin, temp->nama);
            cout << "Masukkan umur baru: ";
            temp->umur = inputInteger();
            cout << "Masukkan jabatan baru: ";
            getline(cin, temp->jabatan);
            cout << "Masukkan gaji baru: ";
            temp->gaji = inputInteger();
            cout << "Data karyawan berhasil diperbarui.\n";
            return;
        }
        temp = temp->next;
    }

    cout << "ID Karyawan tidak ditemukan.\n";
}

void enqueueKaryawan(Karyawan* &front, Karyawan* &rear) {
    Karyawan* baru = new Karyawan;
    
    cout << "Masukkan ID Karyawan: ";
    baru->id = inputInteger();
    
    cin.ignore(); 
    cout << "Masukkan Nama Karyawan: ";
    getline(cin, baru->nama);
    
    cout << "Masukkan Umur Karyawan: ";
    baru->umur = inputInteger();
    
    cout << "Masukkan Jabatan Karyawan: ";
    getline(cin, baru->jabatan);

    cout << "Masukkan Gaji Karyawan: ";
    baru->gaji = inputInteger();
    
    baru->next = nullptr;
    
    if (rear == nullptr) {
        front = rear = baru;
    } else {
        rear->next = baru;
        rear = baru;
    }
    cout << "Karyawan berhasil ditambahkan ke Queue!\n";
}

void dequeueKaryawan(Karyawan* &front, Karyawan* &rear) {
    if (front == nullptr) {
        cout << "Queue kosong, tidak ada karyawan untuk dihapus.\n";
        return;
    }

    Karyawan* temp = front;
    front = front->next;
    if (front == nullptr) {
        rear = nullptr;
    }
    cout << "Karyawan dengan ID " << temp->id << " berhasil dihapus dari Queue.\n";
    delete temp;
}

void tampilkanQueue(Karyawan* front) {
    if (front == nullptr) {
        cout << "Queue kosong.\n";
        return;
    }

    cout << left << setw(5) << "ID" 
         << setw(20) << "Nama" 
         << setw(10) << "Umur" 
         << setw(20) << "Jabatan" 
         << setw(15) << "Gaji" << endl;
    cout << setfill('=') << setw(70) << "=" << setfill(' ') << endl;

    Karyawan* temp = front;
    while (temp != nullptr) {
        cout << left << setw(5) << temp->id 
             << setw(20) << temp->nama 
             << setw(10) << temp->umur 
             << setw(20) << temp->jabatan
             << setw(15) << temp->gaji << endl;
        temp = temp->next;
    }
}

Karyawan* merge(Karyawan* left, Karyawan* right) {
    if (!left)
        return right;
    if (!right)
        return left;
    
    Karyawan* result = nullptr;
    if (left->gaji <= right->gaji) {
        result = left;
        result->next = merge(left->next, right);
    } else {
        result = right;
        result->next = merge(left, right->next);
    }
    return result;
}

void split(Karyawan* source, Karyawan** front, Karyawan** back) {
    Karyawan* fast;
    Karyawan* slow;
    slow = source;
    fast = source->next;
    
    while (fast != nullptr) {
        fast = fast->next;
        if (fast != nullptr) {
            slow = slow->next;
            fast = fast->next;
        }
    }
    
    *front = source;
    *back = slow->next;
    slow->next = nullptr;
}

void mergeSort(Karyawan** headRef) {
    Karyawan* head = *headRef;
    if ((head == nullptr) || (head->next == nullptr)) {
        return;
    }
    
    Karyawan* left;
    Karyawan* right;
    
    split(head, &left, &right);
    
    mergeSort(&left);
    mergeSort(&right);
    
    *headRef = merge(left, right);
}

Karyawan* partition(Karyawan* head, Karyawan** newHead, Karyawan** newEnd) {
    Karyawan* pivot = head;
    Karyawan* prev = nullptr;
    Karyawan* cur = head;
    Karyawan* tail = pivot;
    
    while (cur != nullptr) {
        if (cur->gaji > pivot->gaji) {
            if ((*newHead) == nullptr)
                (*newHead) = cur;
            
            prev = cur;
            cur = cur->next;
        } else {
            if (prev != nullptr)
                prev->next = cur->next;
            Karyawan* temp = cur->next;
            cur->next = nullptr;
            tail->next = cur;
            tail = cur;
            cur = temp;
        }
    }
    
    if ((*newHead) == nullptr)
        (*newHead) = pivot;
    
    (*newEnd) = tail;
    
    return pivot;
}

Karyawan* quickSortRecur(Karyawan* head, Karyawan* end) {
    if (!head || head == end)
        return head;
    
    Karyawan* newHead = nullptr;
    Karyawan* newEnd = nullptr;
    
    Karyawan* pivot = partition(head, &newHead, &newEnd);
    
    if (newHead != pivot) {
        Karyawan* temp = newHead;
        while (temp->next != pivot)
            temp = temp->next;
        temp->next = nullptr;
        
        newHead = quickSortRecur(newHead, temp);
        
        temp = newHead;
        while (temp->next != nullptr)
            temp = temp->next;
        temp->next = pivot;
    }
    
    pivot->next = quickSortRecur(pivot->next, newEnd);
    
    return newHead;
}

void quickSort(Karyawan** headRef) {
    (*headRef) = quickSortRecur(*headRef, nullptr);
}

int main() {
    Karyawan* top = nullptr;
    Karyawan* front = nullptr;
    Karyawan* rear = nullptr;

    int pilihan;
    do {
        cout << "\nSistem Pengelolaan Data Karyawan\n";
        cout << "1. Tambah Karyawan ke Stack\n";
        cout << "2. Tampilkan Karyawan di Stack\n";
        cout << "3. Perbarui Karyawan di Stack\n";
        cout << "4. Tambah Karyawan ke Queue\n";
        cout << "5. Hapus Karyawan dari Queue\n";
        cout << "6. Tampilkan Karyawan di Queue\n";
        cout << "7. Urutkan Karyawan berdasarkan Gaji (Ascending - Merge Sort)\n";
        cout << "8. Urutkan Karyawan berdasarkan Gaji (Descending - Quick Sort)\n";
        cout << "9. Keluar\n";
        cout << "Masukkan pilihan Anda: ";
        pilihan = inputInteger();
        
        switch (pilihan) {
            case 1:
                pushKaryawan(top);
                break;
            case 2:
                tampilkanStack(top);
                break;
            case 3:
                updateKaryawan(top);
                break;
            case 4:
                enqueueKaryawan(front, rear);
                break;
            case 5:
                dequeueKaryawan(front, rear);
                break;
            case 6:
                tampilkanQueue(front);
                break;
            case 7:
                mergeSort(&top);
                cout << "Karyawan berhasil diurutkan secara Ascending berdasarkan Gaji menggunakan Merge Sort.\n";
                break;
            case 8:
                quickSort(&top);
                cout << "Karyawan berhasil diurutkan secara Descending berdasarkan Gaji menggunakan Quick Sort.\n";
                break;
            case 9:
                cout << "Keluar dari program...\n";
                break;
            default:
                cout << "Pilihan tidak valid, coba lagi.\n";
        }
    } while (pilihan != 9);
    
    return 0;
}