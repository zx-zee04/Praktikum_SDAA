#include <iostream>
#include <string>
#include <limits>

using namespace std;

struct Karyawan {
    int id;
    string nama;
    int umur;
    string jabatan;
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

void tambahKaryawan(Karyawan karyawan[], int &jumlah) {
    cout << "Masukkan ID Karyawan: ";
    karyawan[jumlah].id = inputInteger();
    
    cout << "Masukkan Nama Karyawan: ";
    getline(cin, karyawan[jumlah].nama);
    
    cout << "Masukkan Umur Karyawan: ";
    karyawan[jumlah].umur = inputInteger();
    
    cout << "Masukkan Jabatan Karyawan: ";
    getline(cin, karyawan[jumlah].jabatan);
    
    jumlah++;
    cout << "Karyawan berhasil ditambahkan!\n";
}

void tampilkanKaryawan(const Karyawan karyawan[], int jumlah) {
    if (jumlah == 0) {
        cout << "Tidak ada data karyawan.\n";
        return;
    }
    cout << "Data Karyawan:\n";
    for (int i = 0; i < jumlah; i++) {
        cout << "ID: " << karyawan[i].id << "\n";
        cout << "Nama: " << karyawan[i].nama << "\n";
        cout << "Umur: " << karyawan[i].umur << "\n";
        cout << "Jabatan: " << karyawan[i].jabatan << "\n\n";
    }
}

void perbaruiKaryawan(Karyawan karyawan[], int jumlah) {
    int id;
    cout << "Masukkan ID Karyawan yang ingin diperbarui: ";
    id = inputInteger();
    
    for (int i = 0; i < jumlah; i++) {
        if (karyawan[i].id == id) {
            cout << "Masukkan nama baru (sebelumnya: " << karyawan[i].nama << "): ";
            getline(cin, karyawan[i].nama);
            
            cout << "Masukkan umur baru (sebelumnya: " << karyawan[i].umur << "): ";
            karyawan[i].umur = inputInteger();
            
            cout << "Masukkan jabatan baru (sebelumnya: " << karyawan[i].jabatan << "): ";
            getline(cin, karyawan[i].jabatan);
            
            cout << "Data karyawan berhasil diperbarui!\n";
            return;
        }
    }
    cout << "ID Karyawan tidak ditemukan.\n";
}

void hapusKaryawan(Karyawan karyawan[], int &jumlah) {
    int id;
    cout << "Masukkan ID Karyawan yang ingin dihapus: ";
    id = inputInteger();
    
    for (int i = 0; i < jumlah; i++) {
        if (karyawan[i].id == id) {
            for (int j = i; j < jumlah - 1; j++) {
                karyawan[j] = karyawan[j + 1];
            }
            jumlah--;
            cout << "Karyawan berhasil dihapus!\n";
            return;
        }
    }
    cout << "ID Karyawan tidak ditemukan.\n";
}

int main() {
    const int MAKS_KARYAWAN = 100;
    Karyawan karyawan[MAKS_KARYAWAN]; 
    int jumlahKaryawan = 0; 
    
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
                tambahKaryawan(karyawan, jumlahKaryawan);
                break;
            case 2:
                tampilkanKaryawan(karyawan, jumlahKaryawan);
                break;
            case 3:
                perbaruiKaryawan(karyawan, jumlahKaryawan);
                break;
            case 4:
                hapusKaryawan(karyawan, jumlahKaryawan);
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