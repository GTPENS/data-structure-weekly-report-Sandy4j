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
    vector<int> arr = { 64, 25, 12, 22, 11 };

    cout << "Insertion Sort:" << endl;
    insertionSort(arr);
    cout << endl;

    arr = { 64, 25, 12, 22, 11 };
    cout << "Binary Insertion Sort:" << endl;
    binaryInsertionSort(arr);
    cout << endl;

    arr = { 64, 25, 12, 22, 11 };
    cout << "Selection Sort:" << endl;
    selectionSort(arr);

    return 0;
}