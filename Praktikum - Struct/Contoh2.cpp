/*file program : zodiak.c
Menentukan zodiak berdasarkan data tanggal lahir masukan */
#include <stdio.h>
#include <iostream>
#include <string> // Tambahkan untuk menggunakan tipe data string
using namespace std; // Gunakan namespace std untuk menghindari penulisan std::

int main() {
    // Mengganti array char dengan string
    struct Zodiak {
        string nama;
        int tgl_awal;
        int bln_awal;
        int tgl_akhir;
        int bln_akhir;
    };

    // Mengganti inisialisasi statis menggunakan tipe data string
    static Zodiak bintang = { "Sagitarius", 22, 11, 21, 12 };

    int tgl_lhr, bln_lhr, thn_lhr;

    cout << "Masukkan tgl lahir Anda (XX-XX-XXXX): ";
    scanf("%d-%d-%d", &tgl_lhr, &bln_lhr, &thn_lhr);

    // Mengganti array char menjadi string
    if ((tgl_lhr >= bintang.tgl_awal && bln_lhr == bintang.bln_awal) ||
        (tgl_lhr <= bintang.tgl_akhir && bln_lhr == bintang.bln_akhir))
        cout << "Bintang Anda adalah " << bintang.nama << endl;
    else
        cout << "Bintang Anda bukan " << bintang.nama << endl;

    return 0;
}