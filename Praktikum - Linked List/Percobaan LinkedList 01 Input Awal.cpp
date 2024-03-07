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
    cin.getline(baru->nama, 25);
    cout << "NRP: ";
    cin >> baru->nrp;
    cin.ignore(); // Mengabaikan karakter newline tersisa

    if (ujung == nullptr) {
        ujung = baru;
        tampung = baru;
    }
    else {
        baru->next = ujung;
        ujung = baru;
    }
}

int main() {
    sisipUjung();
    return 0;
}