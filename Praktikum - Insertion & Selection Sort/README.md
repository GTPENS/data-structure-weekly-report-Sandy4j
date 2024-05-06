
## Nama    : Yoga Sandy
## NRP     : 52236000023
## Kelas   : 11 GT-A

# Praktikum 06: Overview Insertion & Selection Sort

## Percobaan
Percobaan 1 (Straight Insertion Sort):
```cpp
#include <iostream>
#include <cstdlib>

using namespace std;

#define MAX 10
int Data[MAX];

// Fungsi pengurutan penyisipan langsung
void StraightInsertSort()
{
    int i, j, x;
    for(i=1; i<MAX; i++){
        x = Data[i];
        j = i - 1;
        while (x < Data[j]){
            Data[j+1] = Data[j];
            j--;
        }
        Data[j+1] = x;
    }
}

int main()
{
    int i;
    srand(0);
    // Membangkitkan bilangan acak
    cout << "DATA SEBELUM TERURUT" << endl;
    for(i=0; i<MAX; i++)
    {
        Data[i] = (int) rand()/1000+1;
        cout << "Data ke " << i << " : " << Data[i] << endl;
    }
    StraightInsertSort();
    // Data setelah terurut
    cout << "\nDATA SETELAH TERURUT" << endl;
    for(i=0; i<MAX; i++)
    {
        cout << "Data ke " << i << " : " << Data[i] << endl;
    }
    return 0;
}
```
Percobaan 2 (Binary Insertion Sort):
```cpp
#include <iostream>
#include <cstdlib>

using namespace std;

#define MAX 10
int Data[MAX];

// Fungsi pengurutan penyisipan biner
void BinaryInsertSort()
{
    int i, j, l, r, m, x;
    for (i=1; i<MAX; i++){
        x = Data[i];
        l = 0;
        r = i - 1;
        while(l <= r){
            m = (l + r) / 2;
            if(x < Data[m])
                r = m - 1;
            else
                l = m + 1;
        }
        for(j=i-1; j>=l; j--)
            Data[j+1] = Data[j];
        Data[l]=x;
    }
}

int main()
{
    int i;
    srand(0);
    // Membangkitkan bilangan acak
    cout << "DATA SEBELUM TERURUT" << endl;
    for(i=0; i<MAX; i++)
    {
        Data[i] = (int) rand()/1000+1;
        cout << "Data ke " << i << " : " << Data[i] << endl;
    }
    BinaryInsertSort();
    // Data setelah terurut
    cout << "\nDATA SETELAH TERURUT" << endl;
    for(i=0; i<MAX; i++)
    {
        cout << "Data ke " << i << " : " << Data[i] << endl;
    }
    return 0;
}
```
Percobaan 3 (Selection Sort):
```cpp
#include <iostream>
#include <cstdlib>

using namespace std;

#define MAX 10
int Data[MAX];

// Fungsi pertukaran bilangan
void Tukar (int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

// Fungsi pengurutan seleksi
void SelectionSort()
{
    int i, j, k;
    for(i=0; i<MAX-1;i++){
        k = i;
        for (j=i+1; j<MAX; j++)
            if(Data[k] > Data[j])
                k = j;
        Tukar(&Data[i], &Data[k]);
    }
}

int main()
{
    int i;
    srand(0);
    // Membangkitkan bilangan acak
    cout << "DATA SEBELUM TERURUT" << endl;
    for(i=0; i<MAX; i++)
    {
        Data[i] = (int) rand()/1000+1;
        cout << "Data ke " << i << " : " << Data[i] << endl;
    }
    SelectionSort();
    // Data setelah terurut
    cout << "\nDATA SETELAH TERURUT" << endl;
    for(i=0; i<MAX; i++)
    {
        cout << "Data ke " << i << " : " << Data[i] << endl;
    }
    return 0;
}
```
Penggabungan Semua Kode Diatas
```cpp
#include <iostream>
#include <cstdlib>

using namespace std;

#define MAX 10
int Data[MAX];

// Fungsi pertukaran bilangan
void Tukar(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

// Fungsi pengurutan penyisipan langsung
void StraightInsertSort()
{
    int i, j, x;
    for(i=1; i<MAX; i++){
        x = Data[i];
        j = i - 1;
        while (x < Data[j]){
            Data[j+1] = Data[j];
            j--;
        }
        Data[j+1] = x;
    }
}

// Fungsi pengurutan penyisipan biner
void BinaryInsertSort()
{
    int i, j, l, r, m, x;
    for (i=1; i<MAX; i++){
        x = Data[i];
        l = 0;
        r = i - 1;
        while(l <= r){
            m = (l + r) / 2;
            if(x < Data[m])
                r = m - 1;
            else
                l = m + 1;
        }
        for(j=i-1; j>=l; j--)
            Data[j+1] = Data[j];
        Data[l]=x;
    }
}

// Fungsi pengurutan seleksi
void SelectionSort()
{
    int i, j, k;
    for(i=0; i<MAX-1;i++){
        k = i;
        for (j=i+1; j<MAX; j++)
            if(Data[k] > Data[j])
                k = j;
        Tukar(&Data[i], &Data[k]);
    }
}

int main()
{
    int i, choice;
    srand(0);

    // Membangkitkan bilangan acak
    cout << "DATA SEBELUM TERURUT" << endl;
    for(i=0; i<MAX; i++)
    {
        Data[i] = (int) rand()/1000+1;
        cout << "Data ke " << i << " : " << Data[i] << endl;
    }

    // Menu pilihan metode pengurutan
    cout << "\nPilih metode pengurutan:" << endl;
    cout << "1. Straight Insertion Sort" << endl;
    cout << "2. Binary Insertion Sort" << endl;
    cout << "3. Selection Sort" << endl;
    cout << "Masukkan pilihan Anda: ";
    cin >> choice;

    switch(choice)
    {
        case 1:
            StraightInsertSort();
            break;
        case 2:
            BinaryInsertSort();
            break;
        case 3:
            SelectionSort();
            break;
        default:
            cout << "Pilihan tidak valid." << endl;
            return 0;
    }

    // Data setelah terurut
    cout << "\nDATA SETELAH TERURUT" << endl;
    for(i=0; i<MAX; i++)
    {
        cout << "Data ke " << i << " : " << Data[i] << endl;
    }

    return 0;
}
```

## Latihan

1. Tambahkan kode program untuk menampilkan perubahan setiap iterasi dari proses
pengurutan dengan penyisipan langsung, penyisipan biner dan seleksi.
2. Tambahkan kode program untuk menghitung banyaknya perbandingan dan
pergeseran pada algoritma pengurutan penyisipan langsung, penyisipan biner dan
seleksi.
3. Buatlah project baru untuk Latihan dan implementasikan pengurutan data Pegawai
pada tugas pendahuluan dengan ketentuan :.
a. Metode pengurutan dapat dipilih.
b. Pengurutan dapat dipilih secara urut naik atau turun.
c. Pengurutan dapat dipilih berdasarkan NIP dan NAMA.
d. Gunakan struktur data array.

Latihan 01
```cpp
#include <iostream>
#include <vector>

using namespace std;

// Fungsi untuk menampilkan array
void printArray(vector<int>& arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

// Insertion Sort
void insertionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
        cout << "Iterasi ke-" << i << ": ";
        printArray(arr);
    }
}

// Binary Insertion Sort
void binaryInsertionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int left = 0, right = i;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (key < arr[mid])
                right = mid;
            else
                left = mid + 1;
        }
        for (int j = i; j > left; j--) {
            arr[j] = arr[j - 1];
        }
        arr[left] = key;
        cout << "Iterasi ke-" << i << ": ";
        printArray(arr);
    }
}

// Selection Sort
void selectionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }
        swap(arr[i], arr[minIndex]);
        cout << "Iterasi ke-" << i + 1 << ": ";
        printArray(arr);
    }
}

int main() {
    vector<int> arr = {64, 25, 12, 22, 11};

    cout << "Insertion Sort:" << endl;
    insertionSort(arr);
    cout << endl;

    arr = {64, 25, 12, 22, 11};
    cout << "Binary Insertion Sort:" << endl;
    binaryInsertionSort(arr);
    cout << endl;

    arr = {64, 25, 12, 22, 11};
    cout << "Selection Sort:" << endl;
    selectionSort(arr);

    return 0;
}
```
Latihan 02
```cpp
#include <iostream>
#include <vector>

using namespace std;

// Fungsi untuk menampilkan array
void printArray(vector<int>& arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

// Insertion Sort
void insertionSort(vector<int>& arr, int& comparisons, int& shifts) {
    int n = arr.size();
    comparisons = 0;
    shifts = 0;
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
            shifts++;
            comparisons++;
        }
        arr[j + 1] = key;
        shifts++;
    }
}

// Binary Insertion Sort
void binaryInsertionSort(vector<int>& arr, int& comparisons, int& shifts) {
    int n = arr.size();
    comparisons = 0;
    shifts = 0;
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int left = 0, right = i;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (key < arr[mid]) {
                right = mid;
            } else {
                left = mid + 1;
            }
            comparisons++;
        }
        for (int j = i; j > left; j--) {
            arr[j] = arr[j - 1];
            shifts++;
        }
        arr[left] = key;
        shifts++;
    }
}

// Selection Sort
void selectionSort(vector<int>& arr, int& comparisons, int& shifts) {
    int n = arr.size();
    comparisons = 0;
    shifts = 0;
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
            comparisons++;
        }
        swap(arr[i], arr[minIndex]);
        shifts += 3;  // Setiap swap membutuhkan 3 pergeseran
    }
}

int main() {
    vector<int> arr = {64, 25, 12, 22, 11};

    int comparisons, shifts;

    cout << "Insertion Sort:" << endl;
    insertionSort(arr, comparisons, shifts);
    printArray(arr);
    cout << "Perbandingan: " << comparisons << ", Pergeseran: " << shifts << endl;
    cout << endl;

    arr = {64, 25, 12, 22, 11};
    cout << "Binary Insertion Sort:" << endl;
    binaryInsertionSort(arr, comparisons, shifts);
    printArray(arr);
    cout << "Perbandingan: " << comparisons << ", Pergeseran: " << shifts << endl;
    cout << endl;

    arr = {64, 25, 12, 22, 11};
    cout << "Selection Sort:" << endl;
    selectionSort(arr, comparisons, shifts);
    printArray(arr);
    cout << "Perbandingan: " << comparisons << ", Pergeseran: " << shifts << endl;

    return 0;
}
```
Latihan 03
```cpp
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// Struct untuk menyimpan data Pegawai
struct Pegawai {
    string nip;
    string nama;
};

// Fungsi untuk melakukan pengurutan berdasarkan NIP
bool sortByNIP(const Pegawai& p1, const Pegawai& p2) {
    return p1.nip < p2.nip;
}

// Fungsi untuk melakukan pengurutan berdasarkan Nama
bool sortByNama(const Pegawai& p1, const Pegawai& p2) {
    return p1.nama < p2.nama;
}

// Fungsi untuk menampilkan data Pegawai
void printPegawai(vector<Pegawai>& pegawai) {
    cout << "Data Pegawai:" << endl;
    for (const auto& p : pegawai) {
        cout << "NIP: " << p.nip << ", Nama: " << p.nama << endl;
    }
}

int main() {
    vector<Pegawai> pegawai = {
       {"D001", "Artiani", "Surabaya", "A"},
       {"D002", "Fahim","Surabaya", "A"},
       {"D003", "Kholid","Surabaya", "A"},
       {"D004", "Rizky","Surabaya", "A"},
       {"D005", "Safrodin","Surabaya", "A"}
    };

    int choice;
    bool ascending;
    char sortBy;

    do {
        cout << "Pilih metode pengurutan:" << endl;
        cout << "1. Insertion Sort" << endl;
        cout << "2. Selection Sort" << endl;
        cout << "3. Keluar" << endl;
        cout << "Masukkan pilihan: ";
        cin >> choice;

        if (choice == 1 || choice == 2) {
            cout << "Urutkan secara:" << endl;
            cout << "a. Ascending" << endl;
            cout << "b. Descending" << endl;
            cout << "Masukkan pilihan: ";
            char order;
            cin >> order;
            ascending = (order == 'a');

            cout << "Urutkan berdasarkan:" << endl;
            cout << "n. NIP" << endl;
            cout << "m. Nama" << endl;
            cout << "Masukkan pilihan: ";
            cin >> sortBy;

            if (choice == 1) {
                if (sortBy == 'n') {
                    sort(pegawai.begin(), pegawai.end(), sortByNIP);
                }
                else {
                    sort(pegawai.begin(), pegawai.end(), sortByNama);
                }
            }
            else {
                if (sortBy == 'n') {
                    sort(pegawai.begin(), pegawai.end(), sortByNIP);
                }
                else {
                    sort(pegawai.begin(), pegawai.end(), sortByNama);
                }
            }

            if (!ascending) {
                reverse(pegawai.begin(), pegawai.end());
            }

            printPegawai(pegawai);
        }
    } while (choice != 3);

    return 0;
}
```