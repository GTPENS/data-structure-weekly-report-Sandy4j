#include <iostream>
#include <cstring>

using namespace std;

// Deklarasi Struktur Simpul
struct Simpul {
    char nama[25];
    int nrp;
    Simpul* next;
};

// Deklarasi Variabel Global
Simpul* ujung = nullptr;
Simpul* tampung = nullptr;

// Fungsi Alokasi Simpul
Simpul* alokasi_simpul() {
    Simpul* baru = new Simpul;
    baru->next = nullptr;
    return baru;
}

// Fungsi Menyisipkan Simpul Ujung
void sisipUjung() {
    Simpul* baru = alokasi_simpul();
    cout << "Nama: ";
    cin >> baru->nama;
    cout << "NRP: ";
    cin >> baru->nrp;
    if (ujung == nullptr) {
        ujung = baru;
        tampung = baru;
    }
    else {
        baru->next = ujung;
        ujung = baru;
    }
}

// Fungsi Membaca/Menampilkan Linked List
void tampilkanList() {
    Simpul* tampil = ujung;
    while (tampil != nullptr) {
        cout << "Nama: " << tampil->nama << ", NRP: " << tampil->nrp << endl;
        tampil = tampil->next;
    }
}

// Fungsi Mencari Simpul Tertentu
void cariSimpul(const char* nama) {
    Simpul* cari = ujung;
    bool ditemukan = false;
    while (cari != nullptr) {
        if (strcmp(cari->nama, nama) == 0) {
            cout << "Data ditemukan: " << cari->nama << ", " << cari->nrp << endl;
            ditemukan = true;
            break;
        }
        cari = cari->next;
    }
    if (!ditemukan) {
        cout << "Data tidak ditemukan." << endl;
    }
}

// Fungsi Menyisipkan Simpul Terakhir
void sisipTerakhir() {
    Simpul* baru = alokasi_simpul();
    cout << "Nama: ";
    cin >> baru->nama;
    cout << "NRP: ";
    cin >> baru->nrp;
    if (ujung == nullptr) {
        ujung = baru;
        tampung = baru;
    }
    else {
        Simpul* cari = ujung;
        while (cari->next != nullptr) {
            cari = cari->next;
        }
        cari->next = baru;
    }
}

int main() {
    int pilihan;
    char nama[25];

    do {
        cout << "\nMenu Operasi Linked List:\n";
        cout << "1. Menyisipkan Simpul Ujung\n";
        cout << "2. Menampilkan Linked List\n";
        cout << "3. Mencari Simpul Tertentu\n";
        cout << "4. Menyisipkan Simpul Terakhir\n";
        cout << "5. Keluar\n";
        cout << "Masukkan pilihan: ";
        cin >> pilihan;

        switch (pilihan) {
        case 1:
            sisipUjung();
            break;
        case 2:
            tampilkanList();
            break;
        case 3:
            cout << "Masukkan nama yang ingin dicari: ";
            cin >> nama;
            cariSimpul(nama);
            break;
        case 4:
            sisipTerakhir();
            break;
        case 5:
            cout << "Terima kasih telah menggunakan program ini.\n";
            break;
        default:
            cout << "Pilihan tidak valid!\n";
        }
    } while (pilihan != 5);

    return 0;
}