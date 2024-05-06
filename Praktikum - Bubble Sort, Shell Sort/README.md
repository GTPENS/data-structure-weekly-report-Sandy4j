
## Nama    : Yoga Sandy
## NRP     : 52236000023
## Kelas   : 11 GT-A

# Praktikum 07: Overview Bubble Sort & Shell Sort

## Percobaan
Percobaan 1 : Implementasi pengurutan dengan metode gelembung (bubble sort)
```cpp
#include <iostream>
#include <cstdlib>
using namespace std;

const int MAX = 10;
int Data[MAX];

// Prosedur menukar data
void Tukar(int* a, int* b) {
   int temp = *a;
   *a = *b;
   *b = temp;
}

// Prosedur pengurutan metode gelembung
void BubbleSort() {
   int i, j;
   for (i = 1; i < MAX - 1; i++) {
       for (j = MAX - 1; j >= i; j--) {
           if (Data[j - 1] > Data[j]) {
               Tukar(&Data[j - 1], &Data[j]);
           }
       }
   }
}

int main() {
   int i;
   srand(0);

   // Membangkitkan bilangan acak
   cout << "DATA SEBELUM TERURUT" << endl;
   for (i = 0; i < MAX; i++) {
       Data[i] = rand() / 1000 + 1;
       cout << "Data ke " << i << " : " << Data[i] << endl;
   }

   BubbleSort();

   // Data setelah terurut
   cout << "\nDATA SETELAH TERURUT" << endl;
   for (i = 0; i < MAX; i++) {
       cout << "Data ke " << i << " : " << Data[i] << endl;
   }

   return 0;
}
```
Percobaan 2 : Implementasi pengurutan dengan metode shell (shell sort)
```cpp
#include <iostream>
#include <cstdlib>
using namespace std;

const int MAX = 10;
int Data[MAX];

// Prosedur menukar data
void Tukar(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Prosedur pengurutan metode Shell
void ShellSort() {
    int Jarak, i, j;
    bool Sudah;
    Jarak = MAX;

    while (Jarak > 1) {
        Jarak = Jarak / 2;
        Sudah = false;

        while (!Sudah) {
            Sudah = true;
            for (j = 0; j < MAX - Jarak; j++) {
                i = j + Jarak;
                if (Data[j] > Data[i]) {
                    Tukar(&Data[j], &Data[i]);
                    Sudah = false;
                }
            }
        }
    }
}

int main() {
    int i;
    srand(0);

    // Membangkitkan bilangan acak
    cout << "DATA SEBELUM TERURUT" << endl;
    for (i = 0; i < MAX; i++) {
        Data[i] = rand() / 1000 + 1;
        cout << "Data ke " << i << " : " << Data[i] << endl;
    }

    ShellSort();

    // Data setelah terurut
    cout << "\nDATA SETELAH TERURUT" << endl;
    for (i = 0; i < MAX; i++) {
        cout << "Data ke " << i << " : " << Data[i] << endl;
    }

    return 0;
}
```
Menu Pilihan Bubble Sort dan Shell Sort
```cpp
#include <iostream>
#include <cstdlib>
using namespace std;

const int MAX = 10;
int Data[MAX];

// Prosedur menukar data
void Tukar(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Prosedur pengurutan metode gelembung
void BubbleSort() {
    int i, j;
    for (i = 1; i < MAX - 1; i++) {
        for (j = MAX - 1; j >= i; j--) {
            if (Data[j - 1] > Data[j]) {
                Tukar(&Data[j - 1], &Data[j]);
            }
        }
    }
}

// Prosedur pengurutan metode Shell
void ShellSort() {
    int Jarak, i, j;
    bool Sudah;
    Jarak = MAX;

    while (Jarak > 1) {
        Jarak = Jarak / 2;
        Sudah = false;

        while (!Sudah) {
            Sudah = true;
            for (j = 0; j < MAX - Jarak; j++) {
                i = j + Jarak;
                if (Data[j] > Data[i]) {
                    Tukar(&Data[j], &Data[i]);
                    Sudah = false;
                }
            }
        }
    }
}

int main() {
    int i, pilihan;
    srand(0);

    // Membangkitkan bilangan acak
    cout << "DATA SEBELUM TERURUT" << endl;
    for (i = 0; i < MAX; i++) {
        Data[i] = rand() / 1000 + 1;
        cout << "Data ke " << i << " : " << Data[i] << endl;
    }

    // Menu pilihan metode pengurutan
    cout << "\nPilih metode pengurutan:" << endl;
    cout << "1. Bubble Sort" << endl;
    cout << "2. Shell Sort" << endl;
    cout << "Pilihan Anda: ";
    cin >> pilihan;

    switch (pilihan) {
        case 1:
            BubbleSort();
            cout << "\nData setelah diurutkan dengan Bubble Sort:" << endl;
            break;
        case 2:
            ShellSort();
            cout << "\nData setelah diurutkan dengan Shell Sort:" << endl;
            break;
        default:
            cout << "Pilihan tidak valid!" << endl;
            return 0;
    }

    // Menampilkan data setelah diurutkan
    for (i = 0; i < MAX; i++) {
        cout << "Data ke " << i << " : " << Data[i] << endl;
    }

    return 0;
}
```
## Latihan
1. Tambahkan kode program untuk menampilkan perubahan setiap iterasi dari proses pengurutan dengan metode gelembung dan shell.
```cpp
#include <iostream>
#include <cstdlib>
using namespace std;

const int MAX = 10;
int Data[MAX];

// Prosedur menukar data
void Tukar(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Prosedur pengurutan metode gelembung
void BubbleSort() {
    int i, j;
    for (i = 1; i < MAX - 1; i++) {
        for (j = MAX - 1; j >= i; j--) {
            if (Data[j - 1] > Data[j]) {
                Tukar(&Data[j - 1], &Data[j]);
                cout << "Iterasi " << i << ", Tukar Data[" << j - 1 << "] = " << Data[j - 1] << " dengan Data[" << j << "] = " << Data[j] << endl;
            }
        }
    }
}

// Prosedur pengurutan metode Shell
void ShellSort() {
    int Jarak, i, j;
    bool Sudah;
    Jarak = MAX;

    while (Jarak > 1) {
        Jarak = Jarak / 2;
        Sudah = false;

        while (!Sudah) {
            Sudah = true;
            for (j = 0; j < MAX - Jarak; j++) {
                i = j + Jarak;
                if (Data[j] > Data[i]) {
                    Tukar(&Data[j], &Data[i]);
                    Sudah = false;
                    cout << "Jarak = " << Jarak << ", Tukar Data[" << j << "] = " << Data[j] << " dengan Data[" << i << "] = " << Data[i] << endl;
                }
            }
        }
    }
}

int main() {
    int i, pilihan;
    srand(0);

    // Membangkitkan bilangan acak
    cout << "DATA SEBELUM TERURUT" << endl;
    for (i = 0; i < MAX; i++) {
        Data[i] = rand() / 1000 + 1;
        cout << "Data ke " << i << " : " << Data[i] << endl;
    }

    // Menu pilihan metode pengurutan
    cout << "\nPilih metode pengurutan:" << endl;
    cout << "1. Bubble Sort" << endl;
    cout << "2. Shell Sort" << endl;
    cout << "Pilihan Anda: ";
    cin >> pilihan;

    switch (pilihan) {
        case 1:
            cout << "\nProses Bubble Sort:" << endl;
            BubbleSort();
            cout << "\nData setelah diurutkan dengan Bubble Sort:" << endl;
            break;
        case 2:
            cout << "\nProses Shell Sort:" << endl;
            ShellSort();
            cout << "\nData setelah diurutkan dengan Shell Sort:" << endl;
            break;
        default:
            cout << "Pilihan tidak valid!" << endl;
            return 0;
    }

    // Menampilkan data setelah diurutkan
    for (i = 0; i < MAX; i++) {
        cout << "Data ke " << i << " : " << Data[i] << endl;
    }

    return 0;
}
```
2. Tambahkan kode program untuk menghitung banyaknya perbandingan dan
pergeseran pada algoritma gelembung dan shell.
```cpp
#include <iostream>
#include <cstdlib>
using namespace std;

const int MAX = 10;
int Data[MAX];

// Prosedur menukar data
void Tukar(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Prosedur pengurutan metode gelembung
void BubbleSort(int& comparisons, int& swaps) {
    int i, j;
    comparisons = 0;
    swaps = 0;

    for (i = 1; i < MAX - 1; i++) {
        for (j = MAX - 1; j >= i; j--) {
            comparisons++;
            if (Data[j - 1] > Data[j]) {
                Tukar(&Data[j - 1], &Data[j]);
                swaps++;
            }
        }
    }
}

// Prosedur pengurutan metode Shell
void ShellSort(int& comparisons, int& swaps) {
    int Jarak, i, j;
    bool Sudah;
    Jarak = MAX;
    comparisons = 0;
    swaps = 0;

    while (Jarak > 1) {
        Jarak = Jarak / 2;
        Sudah = false;

        while (!Sudah) {
            Sudah = true;
            for (j = 0; j < MAX - Jarak; j++) {
                i = j + Jarak;
                comparisons++;
                if (Data[j] > Data[i]) {
                    Tukar(&Data[j], &Data[i]);
                    Sudah = false;
                    swaps++;
                }
            }
        }
    }
}

int main() {
    int i, pilihan, comparisons, swaps;
    srand(0);

    // Membangkitkan bilangan acak
    cout << "DATA SEBELUM TERURUT" << endl;
    for (i = 0; i < MAX; i++) {
        Data[i] = rand() / 1000 + 1;
        cout << "Data ke " << i << " : " << Data[i] << endl;
    }

    // Menu pilihan metode pengurutan
    cout << "\nPilih metode pengurutan:" << endl;
    cout << "1. Bubble Sort" << endl;
    cout << "2. Shell Sort" << endl;
    cout << "Pilihan Anda: ";
    cin >> pilihan;

    switch (pilihan) {
        case 1:
            cout << "\nProses Bubble Sort:" << endl;
            BubbleSort(comparisons, swaps);
            cout << "\nData setelah diurutkan dengan Bubble Sort:" << endl;
            cout << "Jumlah Perbandingan: " << comparisons << endl;
            cout << "Jumlah Pergeseran: " << swaps << endl;
            break;
        case 2:
            cout << "\nProses Shell Sort:" << endl;
            ShellSort(comparisons, swaps);
            cout << "\nData setelah diurutkan dengan Shell Sort:" << endl;
            cout << "Jumlah Perbandingan: " << comparisons << endl;
            cout << "Jumlah Pergeseran: " << swaps << endl;
            break;
        default:
            cout << "Pilihan tidak valid!" << endl;
            return 0;
    }

    // Menampilkan data setelah diurutkan
    for (i = 0; i < MAX; i++) {
        cout << "Data ke " << i << " : " << Data[i] << endl;
    }

    return 0;
}
```
3. Implementasikan pengurutan data Pegawai pada tugas pendahuluan dengan
ketentuan :
a. Metode pengurutan dapat dipilih.
b. Pengurutan dapat dipilih secara urut naik atau turun.
c. Pengurutan dapat dipilih berdasarkan NIP dan NAMA.
d. Gunakan struktur data array.
```cpp
#include <iostream>
#include <cstring>
using namespace std;

struct Pegawai {
    string NIP;
    string Nama;
    string Alamat;
    char Golongan;
};

const int MAX_PEGAWAI = 5;
Pegawai dataPegawai[MAX_PEGAWAI] = {
    {"D001", "Artiani", "Surabaya", 'A'},
    {"D002", "Fahim", "Surabaya", 'A'},
    {"D003", "Kholid", "Surabaya", 'A'},
    {"D004", "Rizky", "Surabaya", 'A'},
    {"D005", "Safrodin", "Surabaya", 'A'}
};

void TukarPegawai(Pegawai& a, Pegawai& b) {
    Pegawai temp = a;
    a = b;
    b = temp;
}

void BubbleSortPegawai(bool isAscending, bool sortByNIP) {
    int comparisons = 0, swaps = 0;
    for (int i = 1; i < MAX_PEGAWAI; i++) {
        for (int j = MAX_PEGAWAI - 1; j >= i; j--) {
            comparisons++;
            bool shouldSwap = false;
            if (sortByNIP) {
                shouldSwap = isAscending ? dataPegawai[j - 1].NIP > dataPegawai[j].NIP
                                         : dataPegawai[j - 1].NIP < dataPegawai[j].NIP;
            } else {
                shouldSwap = isAscending ? dataPegawai[j - 1].Nama > dataPegawai[j].Nama
                                         : dataPegawai[j - 1].Nama < dataPegawai[j].Nama;
            }

            if (shouldSwap) {
                TukarPegawai(dataPegawai[j - 1], dataPegawai[j]);
                swaps++;
            }
        }
    }
    cout << "Jumlah Perbandingan: " << comparisons << endl;
    cout << "Jumlah Pergeseran: " << swaps << endl;
}

void ShellSortPegawai(bool isAscending, bool sortByNIP) {
    int comparisons = 0, swaps = 0;
    int jarak, i, j;
    bool sudah;
    jarak = MAX_PEGAWAI;

    while (jarak > 1) {
        jarak = jarak / 2;
        sudah = false;

        while (!sudah) {
            sudah = true;
            for (j = 0; j < MAX_PEGAWAI - jarak; j++) {
                i = j + jarak;
                comparisons++;
                bool shouldSwap = false;
                if (sortByNIP) {
                    shouldSwap = isAscending ? dataPegawai[j].NIP > dataPegawai[i].NIP
                                             : dataPegawai[j].NIP < dataPegawai[i].NIP;
                } else {
                    shouldSwap = isAscending ? dataPegawai[j].Nama > dataPegawai[i].Nama
                                             : dataPegawai[j].Nama < dataPegawai[i].Nama;
                }

                if (shouldSwap) {
                    TukarPegawai(dataPegawai[j], dataPegawai[i]);
                    sudah = false;
                    swaps++;
                }
            }
        }
    }
    cout << "Jumlah Perbandingan: " << comparisons << endl;
    cout << "Jumlah Pergeseran: " << swaps << endl;
}

int main() {
    int pilihan, urutanPilihan, kriteriaPilihan;

    cout << "Data Pegawai Awal:" << endl;
    for (int i = 0; i < MAX_PEGAWAI; i++) {
        cout << "NIP: " << dataPegawai[i].NIP << ", Nama: " << dataPegawai[i].Nama
             << ", Alamat: " << dataPegawai[i].Alamat << ", Golongan: " << dataPegawai[i].Golongan << endl;
    }

    cout << "\nPilih metode pengurutan:" << endl;
    cout << "1. Bubble Sort" << endl;
    cout << "2. Shell Sort" << endl;
    cout << "Pilihan Anda: ";
    cin >> pilihan;

    cout << "\nPilih urutan pengurutan:" << endl;
    cout << "1. Urut Naik" << endl;
    cout << "2. Urut Turun" << endl;
    cout << "Pilihan Anda: ";
    cin >> urutanPilihan;

    cout << "\nPilih kriteria pengurutan:" << endl;
    cout << "1. Berdasarkan NIP" << endl;
    cout << "2. Berdasarkan Nama" << endl;
    cout << "Pilihan Anda: ";
    cin >> kriteriaPilihan;

    bool isAscending = urutanPilihan == 1;
    bool sortByNIP = kriteriaPilihan == 1;

    if (pilihan == 1) {
        BubbleSortPegawai(isAscending, sortByNIP);
        cout << "\nData Pegawai Setelah Diurutkan dengan Bubble Sort:" << endl;
    } else if (pilihan == 2) {
        ShellSortPegawai(isAscending, sortByNIP);
        cout << "\nData Pegawai Setelah Diurutkan dengan Shell Sort:" << endl;
    } else {
        cout << "Pilihan tidak valid!" << endl;
        return 0;
    }

    for (int i = 0; i < MAX_PEGAWAI; i++) {
        cout << "NIP: " << dataPegawai[i].NIP << ", Nama: " << dataPegawai[i].Nama
             << ", Alamat: " << dataPegawai[i].Alamat << ", Golongan: " << dataPegawai[i].Golongan << endl;
    }

    return 0;
}
```