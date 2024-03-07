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

// Fungsi Mencari Simpul Tertentu
void cariSimpul() {
    char nama[25];
    cout << "Masukkan nama yang ingin dicari: ";
    cin.getline(nama, 25);

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

int main() {
    cariSimpul();
    return 0;
}