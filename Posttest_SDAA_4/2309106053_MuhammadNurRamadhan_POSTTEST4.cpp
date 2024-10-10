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

void popKaryawan(Karyawan* &top) {
    if (top == nullptr) {
        cout << "Stack kosong, tidak ada karyawan untuk dihapus.\n";
        return;
    }

    Karyawan* temp = top;
    top = top->next;
    cout << "Karyawan dengan ID " << temp->id << " berhasil dihapus dari Stack.\n";
    delete temp;
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

int main() {
    Karyawan* top = nullptr;
    Karyawan* front = nullptr;
    Karyawan* rear = nullptr;

    int pilihan;
    do {
        cout << "\nSistem Pengelolaan Data Karyawan\n";
        cout << "1. Tambah Karyawan ke Stack\n";
        cout << "2. Hapus Karyawan dari Stack (Pop)\n";
        cout << "3. Tampilkan Karyawan di Stack\n";
        cout << "4. Tambah Karyawan ke Queue\n";
        cout << "5. Hapus Karyawan dari Queue (Dequeue)\n";
        cout << "6. Tampilkan Karyawan di Queue\n";
        cout << "7. Keluar\n";
        cout << "Masukkan pilihan Anda: ";
        pilihan = inputInteger();
        
        switch (pilihan) {
            case 1:
                pushKaryawan(top);
                break;
            case 2:
                popKaryawan(top);
                break;
            case 3:
                tampilkanStack(top);
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
                cout << "Keluar dari program...\n";
                break;
            default:
                cout << "Pilihan tidak valid, coba lagi.\n";
        }
    } while (pilihan != 7);
    
    return 0;
}
