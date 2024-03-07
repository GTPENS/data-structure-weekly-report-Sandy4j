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

// Fungsi Membaca/Menampilkan Linked List
void tampilkanList() {
    Simpul* tampil = ujung;
    if (tampil == nullptr) {
        cout << "Linked List kosong." << endl;
        return;
    }

    cout << "Isi Linked List:" << endl;
    while (tampil != nullptr) {
        cout << "Nama: " << tampil->nama << ", NRP: " << tampil->nrp << endl;
        tampil = tampil->next;
    }
}

int main() {
    tampilkanList();
    return 0;
}