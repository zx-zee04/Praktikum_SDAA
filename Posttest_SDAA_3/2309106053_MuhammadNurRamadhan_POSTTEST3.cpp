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
            cout << "Input tidak valid. Masukkan angka: ";
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return nilai;
        }
    }
}

void tambahKaryawan(Karyawan* &head) {
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
    
    if (head == nullptr) {
        head = baru;
    } else {
        Karyawan* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = baru;
    }
    cout << "Karyawan berhasil ditambahkan!\n";
}

void tampilkanKaryawan(Karyawan* head) {
    if (head == nullptr) {
        cout << "Tidak ada data karyawan.\n";
        return;
    }

    cout << left << setw(5) << "ID" 
         << setw(20) << "Nama" 
         << setw(10) << "Umur" 
         << setw(20) << "Jabatan" 
         << setw(15) << "Gaji" << endl;
    cout << setfill('=') << setw(70) << "=" << setfill(' ') << endl;

    Karyawan* temp = head;
    while (temp != nullptr) {
        cout << left << setw(5) << temp->id 
             << setw(20) << temp->nama 
             << setw(10) << temp->umur 
             << setw(20) << temp->jabatan
             << setw(15) << temp->gaji << endl;
        temp = temp->next;
    }
}

void perbaruiKaryawan(Karyawan* head) {
    int id;
    cout << "Masukkan ID Karyawan yang ingin diperbarui: ";
    id = inputInteger();
    
    Karyawan* temp = head;
    while (temp != nullptr) {
        if (temp->id == id) {
            cin.ignore();
            cout << "Masukkan nama baru (sebelumnya: " << temp->nama << "): ";
            getline(cin, temp->nama);
            
            cout << "Masukkan umur baru (sebelumnya: " << temp->umur << "): ";
            temp->umur = inputInteger();
            
            cout << "Masukkan jabatan baru (sebelumnya: " << temp->jabatan << "): ";
            getline(cin, temp->jabatan);

            cout << "Masukkan gaji baru (sebelumnya: " << temp->gaji << "): ";
            temp->gaji = inputInteger();
            
            cout << "Data karyawan berhasil diperbarui!\n";
            return;
        }
        temp = temp->next;
    }
    cout << "ID Karyawan tidak ditemukan.\n";
}

void hapusKaryawan(Karyawan* &head) {
    int id;
    cout << "Masukkan ID Karyawan yang ingin dihapus: ";
    id = inputInteger();
    
    Karyawan* temp = head;
    Karyawan* prev = nullptr;
    
    if (temp != nullptr && temp->id == id) {
        head = temp->next;
        delete temp;
        cout << "Karyawan berhasil dihapus!\n";
        return;
    }
    
    while (temp != nullptr && temp->id != id) {
        prev = temp;
        temp = temp->next;
    }
    
    if (temp == nullptr) {
        cout << "ID Karyawan tidak ditemukan.\n";
        return;
    }
    
    prev->next = temp->next;
    delete temp;
    cout << "Karyawan berhasil dihapus!\n";
}

int main() {
    Karyawan* head = nullptr;
    
    int pilihan;
    do {
        cout << "\nSistem Pengelolaan Data Karyawan\n";
        cout << "1. Tambah Karyawan\n";
        cout << "2. Tampilkan Karyawan\n";
        cout << "3. Perbarui Karyawan\n";
        cout << "4. Hapus Karyawan\n";
        cout << "5. Keluar\n";
        cout << "Masukkan pilihan Anda: ";
        pilihan = inputInteger();
        
        switch (pilihan) {
            case 1:
                tambahKaryawan(head);
                break;
            case 2:
                tampilkanKaryawan(head);
                break;
            case 3:
                perbaruiKaryawan(head);
                break;
            case 4:
                hapusKaryawan(head);
                break;
            case 5:
                cout << "Keluar dari program...\n";
                break;
            default:
                cout << "Pilihan tidak valid, coba lagi.\n";
        }
    } while (pilihan != 5);
    
    return 0;
}
