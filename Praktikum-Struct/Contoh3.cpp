#include <iostream>
#include <string> // Tambahkan untuk menggunakan tipe data string
#include <limits> // untuk limit numeric
using namespace std;

#define MAKS 20

struct Date {
    int month;
    int day;
    int year;
};

struct Student {
    string name;
    Date birthday;
};

Student data_mhs[MAKS]; // Menggunakan array struktur secara global

int main() {
    int i = 0, jml;
    char lagi;

    // Memasukkan data
    do {
        cout << "Name : ";
        getline(cin, data_mhs[i].name); // Mengganti fgets dengan getline untuk membaca baris
        cout << "Birthday (mm-dd-yyyy): ";
        cin >> data_mhs[i].birthday.month >> data_mhs[i].birthday.day >> data_mhs[i].birthday.year;
        cout << endl;
        i++;

        cout << "Mau memasukkan data lagi [Y/T] ? ";
        do {
            cin >> lagi; // Baca karakter
        } while (tolower(lagi) != 'y' && tolower(lagi) != 't'); // Ubah ke huruf kecil dan periksa

        // Hapus sisa data dalam penampung keyboard
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << endl;
    } while (lagi == 'y');

    jml = i;

    // Menampilkan data
    cout << "DATA SISWA" << endl;
    for (i = 0; i < jml; i++) {
        cout << i + 1 << ". Name : " << data_mhs[i].name << endl;
        cout << "   Birthday : " << data_mhs[i].birthday.month << "-"
            << data_mhs[i].birthday.day << "-" << data_mhs[i].birthday.year << endl
            << endl;
    }

    return 0;
}