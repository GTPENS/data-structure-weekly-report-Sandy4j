## Nama    : Yoga Sandy
## NRP     : 52236000023
## Kelas   : 11 GT-A

# Praktikum Overview Linked List

1. **Menyisipkan Simpul Ujung**

Implementasikan operasi dasar Single Linked List untuk menyisipkan simpul baru sebagai simpul ujung (awal) dari linked list.

```cpp
// Fungsi Menyisipkan Simpul Ujung
void sisipUjung() {
    Simpul* baru = alokasi_simpul();
    cout << "Nama: ";
    cin.getline(baru->nama, 25);
    cout << "NRP: ";
    cin >> baru->nrp;
    cin.ignore();

    if (ujung == nullptr) {
        ujung = baru;
        tampung = baru;
    } else {
        baru->next = ujung;
        ujung = baru;
    }
}
```

2. **Membaca/Menampilkan Linked List**

Implementasikan operasi dasar Single Linked List untuk membaca atau menampilkan isi dari linked list.
```cpp
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
```

3. **Mencari Simpul Tertentu**

Implementasikan operasi dasar Single Linked List untuk mencari sebuah simpul tertentu berdasarkan nama.
```cpp
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
```

4. **Menyisipkan Simpul Terakhir**

Implementasikan operasi dasar Single Linked List untuk menyisipkan simpul baru sebagai simpul terakhir dalam linked list.
```cpp
// Fungsi Menyisipkan Simpul Terakhir
void sisipTerakhir() {
    Simpul* baru = alokasi_simpul();
    cout << "Nama: ";
    cin.getline(baru->nama, 25);
    cout << "NRP: ";
    cin >> baru->nrp;
    cin.ignore();

    if (ujung == nullptr) {
        ujung = baru;
        tampung = baru;
    } else {
        Simpul* cari = ujung;
        while (cari->next != nullptr) {
            cari = cari->next;
        }
        cari->next = baru;
    }
}
```

5. **Menggabungkan Semua Operasi dalam Satu Menu Pilihan**

Gabungkan semua operasi di atas ke dalam sebuah menu pilihan agar pengguna dapat memilih operasi yang diinginkan.
```cpp
int main() {
    int pilihan;

    do {
        cout << "\nMenu Operasi Linked List:\n";
        cout << "1. Menyisipkan Simpul Ujung\n";
        cout << "2. Menampilkan Linked List\n";
        cout << "3. Mencari Simpul Tertentu\n";
        cout << "4. Menyisipkan Simpul Terakhir\n";
        cout << "5. Keluar\n";
        cout << "Masukkan pilihan: ";
        cin >> pilihan;
        cin.ignore(); // Mengabaikan karakter newline tersisa

        switch (pilihan) {
            case 1:
                sisipUjung();
                break;
            case 2:
                tampilkanList();
                break;
            case 3:
                cariSimpul();
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
```

