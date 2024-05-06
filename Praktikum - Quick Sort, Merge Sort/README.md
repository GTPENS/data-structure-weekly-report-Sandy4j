## Nama    : Yoga Sandy
## NRP     : 52236000023
## Kelas   : 11 GT-A

# Praktikum 08: Overview Quick Sort & Merge Sort

## Percobaan
Percobaan 1 : Implementasi pengurutan dengan metode quick sort non rekursif
```cpp
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

#define MAX 10
#define MAXSTACK 10

struct Stack {
    int left;
    int right;
};

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void quickSortNonRecursive(int arr[]) {
    Stack stack[MAXSTACK];
    int top = 0;
    int l, r, i, j, x;

    stack[top].left = 0;
    stack[top].right = MAX - 1;
    top++;

    while (top > 0) {
        top--;
        l = stack[top].left;
        r = stack[top].right;

        while (r > l) {
            i = l;
            j = r;
            x = arr[(l + r) / 2];

            while (i <= j) {
                while (arr[i] < x) i++;
                while (arr[j] > x) j--;

                if (i <= j) {
                    swap(&arr[i], &arr[j]);
                    i++;
                    j--;
                }
            }

            if (l < j) {
                top++;
                stack[top].left = l;
                stack[top].right = j;
            }

            r = j;
        }
    }
}

int main() {
    int arr[MAX];
    srand(time(NULL));

    cout << "Data sebelum terurut: ";
    for (int i = 0; i < MAX; i++) {
        arr[i] = rand() % 100;
        cout << arr[i] << " ";
    }
    cout << endl;

    quickSortNonRecursive(arr);

    cout << "Data setelah terurut: ";
    for (int i = 0; i < MAX; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}
```
Percobaan 2 : Implementasi pengurutan dengan metode quick sort rekursif
```cpp
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

#define MAX 10

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void quickSortRecursive(int arr[], int l, int r) {
    int i, j, x;

    x = arr[(l + r) / 2];
    i = l;
    j = r;

    while (i <= j) {
        while (arr[i] < x) i++;
        while (arr[j] > x) j--;

        if (i <= j) {
            swap(&arr[i], &arr[j]);
            i++;
            j--;
        }
    }

    if (l < j)
        quickSortRecursive(arr, l, j);
    if (i < r)
        quickSortRecursive(arr, i, r);
}

int main() {
    int arr[MAX];
    srand(time(NULL));

    cout << "Data sebelum terurut: ";
    for (int i = 0; i < MAX; i++) {
        arr[i] = rand() % 100;
        cout << arr[i] << " ";
    }
    cout << endl;

    quickSortRecursive(arr, 0, MAX - 1);

    cout << "Data setelah terurut: ";
    for (int i = 0; i < MAX; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}
```
Percobaan 3 : Implementasi pengurutan dengan metode merge sort
```cpp
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

#define MAX 10

void merge(int arr[], int temp[], int left, int mid, int right) {
    int i, j, k;
    i = left;
    j = mid;
    k = left;

    while (i <= mid - 1 && j <= right) {
        if (arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }

    while (i <= mid - 1)
        temp[k++] = arr[i++];

    while (j <= right)
        temp[k++] = arr[j++];

    for (i = left; i <= right; i++)
        arr[i] = temp[i];
}

void mergeSort(int arr[], int temp[], int left, int right) {
    int mid;
    if (left < right) {
        mid = (left + right) / 2;
        mergeSort(arr, temp, left, mid);
        mergeSort(arr, temp, mid + 1, right);
        merge(arr, temp, left, mid + 1, right);
    }
}

int main() {
    int arr[MAX];
    int temp[MAX];
    srand(time(NULL));

    cout << "Data sebelum terurut: ";
    for (int i = 0; i < MAX; i++) {
        arr[i] = rand() % 100;
        cout << arr[i] << " ";
    }
    cout << endl;

    mergeSort(arr, temp, 0, MAX - 1);

    cout << "Data setelah terurut: ";
    for (int i = 0; i < MAX; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}
```
Menu Pilihan Sort
```cpp
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

#define MAX 10
#define MAXSTACK 10

struct Stack {
    int left;
    int right;
};

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Percobaan 1: Implementasi pengurutan dengan metode Quick Sort Non-Rekursif
void quickSortNonRecursive(int arr[]) {
    Stack stack[MAXSTACK];
    int top = 0;
    int l, r, i, j, x;

    stack[top].left = 0;
    stack[top].right = MAX - 1;
    top++;

    while (top > 0) {
        top--;
        l = stack[top].left;
        r = stack[top].right;

        while (r > l) {
            i = l;
            j = r;
            x = arr[(l + r) / 2];

            while (i <= j) {
                while (arr[i] < x) i++;
                while (arr[j] > x) j--;

                if (i <= j) {
                    swap(&arr[i], &arr[j]);
                    i++;
                    j--;
                }
            }

            if (l < j) {
                top++;
                stack[top].left = l;
                stack[top].right = j;
            }

            r = j;
        }
    }
}

// Percobaan 2: Implementasi pengurutan dengan metode Quick Sort Rekursif
void quickSortRecursive(int arr[], int l, int r) {
    int i, j, x;

    x = arr[(l + r) / 2];
    i = l;
    j = r;

    while (i <= j) {
        while (arr[i] < x) i++;
        while (arr[j] > x) j--;

        if (i <= j) {
            swap(&arr[i], &arr[j]);
            i++;
            j--;
        }
    }

    if (l < j)
        quickSortRecursive(arr, l, j);
    if (i < r)
        quickSortRecursive(arr, i, r);
}

// Percobaan 3: Implementasi pengurutan dengan metode Merge Sort
void merge(int arr[], int temp[], int left, int mid, int right) {
    int i, j, k;
    i = left;
    j = mid;
    k = left;

    while (i <= mid - 1 && j <= right) {
        if (arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }

    while (i <= mid - 1)
        temp[k++] = arr[i++];

    while (j <= right)
        temp[k++] = arr[j++];

    for (i = left; i <= right; i++)
        arr[i] = temp[i];
}

void mergeSort(int arr[], int temp[], int left, int right) {
    int mid;
    if (left < right) {
        mid = (left + right) / 2;
        mergeSort(arr, temp, left, mid);
        mergeSort(arr, temp, mid + 1, right);
        merge(arr, temp, left, mid + 1, right);
    }
}

int main() {
    int arr[MAX];
    int temp[MAX];
    int choice;
    srand(time(NULL));

    cout << "Data sebelum terurut: ";
    for (int i = 0; i < MAX; i++) {
        arr[i] = rand() % 100;
        cout << arr[i] << " ";
    }
    cout << endl << endl;

    cout << "Pilih metode pengurutan:" << endl;
    cout << "1. Quick Sort Non-Rekursif" << endl;
    cout << "2. Quick Sort Rekursif" << endl;
    cout << "3. Merge Sort" << endl;
    cout << "Masukkan pilihan Anda (1-3): ";
    cin >> choice;

    switch (choice) {
        case 1:
            quickSortNonRecursive(arr);
            break;
        case 2:
            quickSortRecursive(arr, 0, MAX - 1);
            break;
        case 3:
            mergeSort(arr, temp, 0, MAX - 1);
            break;
        default:
            cout << "Pilihan tidak valid!" << endl;
            return 0;
    }

    cout << "Data setelah terurut: ";
    for (int i = 0; i < MAX; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}
```

## Latihan
1. Tambahkan kode program untuk menampilkan perubahan setiap iterasi dari proses
pengurutan dengan quick sort dan merge sort.
```cpp
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

#define MAX 10
#define MAXSTACK 10

struct Stack {
    int left;
    int right;
};

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Percobaan 1: Implementasi pengurutan dengan metode Quick Sort Non-Rekursif
void quickSortNonRecursive(int arr[]) {
    Stack stack[MAXSTACK];
    int top = 0;
    int l, r, i, j, x;

    stack[top].left = 0;
    stack[top].right = MAX - 1;
    top++;

    while (top > 0) {
        top--;
        l = stack[top].left;
        r = stack[top].right;

        while (r > l) {
            i = l;
            j = r;
            x = arr[(l + r) / 2];

            while (i <= j) {
                while (arr[i] < x) i++;
                while (arr[j] > x) j--;

                if (i <= j) {
                    swap(&arr[i], &arr[j]);
                    i++;
                    j--;
                }
            }

            if (l < j) {
                top++;
                stack[top].left = l;
                stack[top].right = j;
            }

            r = j;
        }

        // Tampilkan perubahan setiap iterasi
        cout << "Iterasi: ";
        for (int k = 0; k < MAX; k++) {
            cout << arr[k] << " ";
        }
        cout << endl;
    }
}

// Percobaan 2: Implementasi pengurutan dengan metode Quick Sort Rekursif
void quickSortRecursive(int arr[], int l, int r) {
    int i, j, x;

    x = arr[(l + r) / 2];
    i = l;
    j = r;

    while (i <= j) {
        while (arr[i] < x) i++;
        while (arr[j] > x) j--;

        if (i <= j) {
            swap(&arr[i], &arr[j]);
            i++;
            j--;
        }
    }

    // Tampilkan perubahan setiap iterasi
    cout << "Iterasi: ";
    for (int k = 0; k < MAX; k++) {
        cout << arr[k] << " ";
    }
    cout << endl;

    if (l < j)
        quickSortRecursive(arr, l, j);
    if (i < r)
        quickSortRecursive(arr, i, r);
}

// Percobaan 3: Implementasi pengurutan dengan metode Merge Sort
void merge(int arr[], int temp[], int left, int mid, int right) {
    int i, j, k;
    i = left;
    j = mid;
    k = left;

    while (i <= mid - 1 && j <= right) {
        if (arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }

    while (i <= mid - 1)
        temp[k++] = arr[i++];

    while (j <= right)
        temp[k++] = arr[j++];

    for (i = left; i <= right; i++)
        arr[i] = temp[i];
}

void mergeSort(int arr[], int temp[], int left, int right) {
    int mid;
    if (left < right) {
        mid = (left + right) / 2;
        mergeSort(arr, temp, left, mid);
        mergeSort(arr, temp, mid + 1, right);

        // Tampilkan perubahan setiap iterasi
        cout << "Iterasi: ";
        for (int k = 0; k < MAX; k++) {
            cout << arr[k] << " ";
        }
        cout << endl;

        merge(arr, temp, left, mid + 1, right);
    }
}

int main() {
    int arr[MAX];
    int temp[MAX];
    int choice;
    srand(time(NULL));

    cout << "Data sebelum terurut: ";
    for (int i = 0; i < MAX; i++) {
        arr[i] = rand() % 100;
        cout << arr[i] << " ";
    }
    cout << endl << endl;

    cout << "Pilih metode pengurutan:" << endl;
    cout << "1. Quick Sort Non-Rekursif" << endl;
    cout << "2. Quick Sort Rekursif" << endl;
    cout << "3. Merge Sort" << endl;
    cout << "Masukkan pilihan Anda (1-3): ";
    cin >> choice;

    switch (choice) {
        case 1:
            quickSortNonRecursive(arr);
            break;
        case 2:
            quickSortRecursive(arr, 0, MAX - 1);
            break;
        case 3:
            mergeSort(arr, temp, 0, MAX - 1);
            break;
        default:
            cout << "Pilihan tidak valid!" << endl;
            return 0;
    }

    cout << "Data setelah terurut: ";
    for (int i = 0; i < MAX; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}
```
2. Tambahkan kode program untuk menghitung banyaknya perbandingan dan
pergeseran pada algoritma quick sort dan merge sort.
```cpp
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

#define MAX 10
#define MAXSTACK 10

int comparisons = 0; // Variabel untuk menyimpan jumlah perbandingan
int swaps = 0; // Variabel untuk menyimpan jumlah pergeseran

struct Stack {
    int left;
    int right;
};

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
    swaps++; // Menghitung jumlah pergeseran
}

// Percobaan 1: Implementasi pengurutan dengan metode Quick Sort Non-Rekursif
void quickSortNonRecursive(int arr[]) {
    Stack stack[MAXSTACK];
    int top = 0;
    int l, r, i, j, x;

    stack[top].left = 0;
    stack[top].right = MAX - 1;
    top++;

    while (top > 0) {
        top--;
        l = stack[top].left;
        r = stack[top].right;

        while (r > l) {
            i = l;
            j = r;
            x = arr[(l + r) / 2];

            while (i <= j) {
                while (arr[i] < x) {
                    i++;
                    comparisons++; // Menghitung jumlah perbandingan
                }
                while (arr[j] > x) {
                    j--;
                    comparisons++; // Menghitung jumlah perbandingan
                }

                if (i <= j) {
                    swap(&arr[i], &arr[j]);
                    i++;
                    j--;
                }
            }

            if (l < j) {
                top++;
                stack[top].left = l;
                stack[top].right = j;
            }

            r = j;
        }
    }
}

// Percobaan 2: Implementasi pengurutan dengan metode Quick Sort Rekursif
void quickSortRecursive(int arr[], int l, int r) {
    int i, j, x;

    x = arr[(l + r) / 2];
    i = l;
    j = r;

    while (i <= j) {
        while (arr[i] < x) {
            i++;
            comparisons++; // Menghitung jumlah perbandingan
        }
        while (arr[j] > x) {
            j--;
            comparisons++; // Menghitung jumlah perbandingan
        }

        if (i <= j) {
            swap(&arr[i], &arr[j]);
            i++;
            j--;
        }
    }

    if (l < j)
        quickSortRecursive(arr, l, j);
    if (i < r)
        quickSortRecursive(arr, i, r);
}

// Percobaan 3: Implementasi pengurutan dengan metode Merge Sort
void merge(int arr[], int temp[], int left, int mid, int right) {
    int i, j, k;
    i = left;
    j = mid;
    k = left;

    while (i <= mid - 1 && j <= right) {
        comparisons++; // Menghitung jumlah perbandingan
        if (arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }

    while (i <= mid - 1) {
        temp[k++] = arr[i++];
        swaps++; // Menghitung jumlah pergeseran
    }

    while (j <= right) {
        temp[k++] = arr[j++];
        swaps++; // Menghitung jumlah pergeseran
    }

    for (i = left; i <= right; i++) {
        arr[i] = temp[i];
        swaps++; // Menghitung jumlah pergeseran
    }
}

void mergeSort(int arr[], int temp[], int left, int right) {
    int mid;
    if (left < right) {
        mid = (left + right) / 2;
        mergeSort(arr, temp, left, mid);
        mergeSort(arr, temp, mid + 1, right);
        merge(arr, temp, left, mid + 1, right);
    }
}

int main() {
    int arr[MAX];
    int temp[MAX];
    int choice;
    srand(time(NULL));

    cout << "Data sebelum terurut: ";
    for (int i = 0; i < MAX; i++) {
        arr[i] = rand() % 100;
        cout << arr[i] << " ";
    }
    cout << endl << endl;

    cout << "Pilih metode pengurutan:" << endl;
    cout << "1. Quick Sort Non-Rekursif" << endl;
    cout << "2. Quick Sort Rekursif" << endl;
    cout << "3. Merge Sort" << endl;
    cout << "Masukkan pilihan Anda (1-3): ";
    cin >> choice;

    switch (choice) {
        case 1:
            quickSortNonRecursive(arr);
            break;
        case 2:
            quickSortRecursive(arr, 0, MAX - 1);
            break;
        case 3:
            mergeSort(arr, temp, 0, MAX - 1);
            break;
        default:
            cout << "Pilihan tidak valid!" << endl;
            return 0;
    }

    cout << "Data setelah terurut: ";
    for (int i = 0; i < MAX; i++)
        cout << arr[i] << " ";
    cout << endl;

    cout << "Jumlah perbandingan: " << comparisons << endl;
    cout << "Jumlah pergeseran: " << swaps << endl;

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
#include <cctype>

using namespace std;

struct Pegawai {
    string NIP;
    string Nama;
    string Alamat;
    char Golongan;
};

const int MAX_PEGAWAI = 5;
Pegawai dataPegawai[MAX_PEGAWAI] = {
    {"D003", "Kholid", "Surabaya", 'A'},
    {"D005", "Safrodin", "Surabaya", 'A'},
    {"D001", "Artiani", "Surabaya", 'A'},
    {"D004", "Rizky", "Surabaya", 'A'},
    {"D002", "Fahim", "Surabaya", 'A'}
};

void swap(Pegawai& a, Pegawai& b) {
    Pegawai temp = a;
    a = b;
    b = temp;
}

void quickSortNIP(Pegawai arr[], int left, int right, bool ascending) {
    int i = left, j = right;
    string pivot = arr[(left + right) / 2].NIP;

    while (i <= j) {
        while (ascending ? arr[i].NIP < pivot : arr[i].NIP > pivot)
            i++;
        while (ascending ? arr[j].NIP > pivot : arr[j].NIP < pivot)
            j--;

        if (i <= j) {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }

    if (left < j)
        quickSortNIP(arr, left, j, ascending);
    if (i < right)
        quickSortNIP(arr, i, right, ascending);
}

void quickSortNama(Pegawai arr[], int left, int right, bool ascending) {
    int i = left, j = right;
    string pivot = arr[(left + right) / 2].Nama;

    while (i <= j) {
        while (ascending ? arr[i].Nama < pivot : arr[i].Nama > pivot)
            i++;
        while (ascending ? arr[j].Nama > pivot : arr[j].Nama < pivot)
            j--;

        if (i <= j) {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }

    if (left < j)
        quickSortNama(arr, left, j, ascending);
    if (i < right)
        quickSortNama(arr, i, right, ascending);
}

void merge(Pegawai temp[], int left, int mid, int right, bool ascending, bool byNIP) {
    int i = left, j = mid + 1, k = left;

    while (i <= mid && j <= right) {
        if (byNIP) {
            if (ascending ? temp[i].NIP < temp[j].NIP : temp[i].NIP > temp[j].NIP)
                dataPegawai[k++] = temp[i++];
            else
                dataPegawai[k++] = temp[j++];
        } else {
            if (ascending ? temp[i].Nama < temp[j].Nama : temp[i].Nama > temp[j].Nama)
                dataPegawai[k++] = temp[i++];
            else
                dataPegawai[k++] = temp[j++];
        }
    }

    while (i <= mid)
        dataPegawai[k++] = temp[i++];

    while (j <= right)
        dataPegawai[k++] = temp[j++];
}

void mergeSortNIP(Pegawai temp[], int left, int right, bool ascending) {
    if (left < right) {
        int mid = (left + right) / 2;
        mergeSortNIP(temp, left, mid, ascending);
        mergeSortNIP(temp, mid + 1, right, ascending);
        merge(temp, left, mid, right, ascending, true);
    }
}

void mergeSortNama(Pegawai temp[], int left, int right, bool ascending) {
    if (left < right) {
        int mid = (left + right) / 2;
        mergeSortNama(temp, left, mid, ascending);
        mergeSortNama(temp, mid + 1, right, ascending);
        merge(temp, left, mid, right, ascending, false);
    }
}

int main() {
    int choice, sortBy;
    bool ascending;
    Pegawai temp[MAX_PEGAWAI];

    cout << "Data Pegawai:" << endl;
    for (int i = 0; i < MAX_PEGAWAI; i++) {
        cout << "NIP: " << dataPegawai[i].NIP << ", Nama: " << dataPegawai[i].Nama
             << ", Alamat: " << dataPegawai[i].Alamat << ", Golongan: " << dataPegawai[i].Golongan << endl;
    }

    cout << "\nPilih metode pengurutan:" << endl;
    cout << "1. Quick Sort" << endl;
    cout << "2. Merge Sort" << endl;
    cout << "Masukkan pilihan (1 atau 2): ";
    cin >> choice;

    if (choice != 1 && choice != 2) {
        cout << "Pilihan tidak valid!" << endl;
        return 0;
    }

    cout << "\nPilih urutan:" << endl;
    cout << "1. Naik" << endl;
    cout << "2. Turun" << endl;
    cout << "Masukkan pilihan (1 atau 2): ";
    cin >> choice;
    ascending = (choice == 1);

    cout << "\nPilih kriteria pengurutan:" << endl;
    cout << "1. NIP" << endl;
    cout << "2. Nama" << endl;
    cout << "Masukkan pilihan (1 atau 2): ";
    cin >> sortBy;

    for (int i = 0; i < MAX_PEGAWAI; i++)
        temp[i] = dataPegawai[i];

    if (sortBy == 1) {
        if (choice == 1)
            quickSortNIP(dataPegawai, 0, MAX_PEGAWAI - 1, ascending);
        else
            mergeSortNIP(temp, 0, MAX_PEGAWAI - 1, ascending);
    } else if (sortBy == 2) {
        if (choice == 1)
            quickSortNama(dataPegawai, 0, MAX_PEGAWAI - 1, ascending);
        else
            mergeSortNama(temp, 0, MAX_PEGAWAI - 1, ascending);
    } else {
        cout << "Pilihan tidak valid!" << endl;
        return 0;
    }

    cout << "\nData Pegawai setelah diurutkan:" << endl;
    for (int i = 0; i < MAX_PEGAWAI; i++) {
        cout << "NIP: " << dataPegawai[i].NIP << ", Nama: " << dataPegawai[i].Nama
             << ", Alamat: " << dataPegawai[i].Alamat << ", Golongan: " << dataPegawai[i].Golongan << endl;
    }

    return 0;
}
```