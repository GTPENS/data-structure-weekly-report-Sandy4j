#include <iostream>
using namespace std;

// Definisikan struktur koordinat sebagai global
struct Koordinat {
    int x;
    int y;
};

// Deklarasi fungsi tukar_xy dengan parameter bertipe pointer ke Koordinat
void tukar_xy(Koordinat*);

int main() {
    // Gunakan struktur Koordinat
    Koordinat posisi;

    cout << "Masukkan koordinat posisi (x, y): ";
    cin >> posisi.x >> posisi.y;

    cout << "x, y semula = " << posisi.x << ", " << posisi.y << endl;

    tukar_xy(&posisi);

    cout << "x, y sekarang = " << posisi.x << ", " << posisi.y << endl;

    return 0;
}

// Implementasi fungsi tukar_xy dengan parameter bertipe pointer ke Koordinat
void tukar_xy(Koordinat* pos_xy) {
    int z;
    z = pos_xy->x;
    pos_xy->x = pos_xy->y;
    pos_xy->y = z;
}