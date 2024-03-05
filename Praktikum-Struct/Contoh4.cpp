#include <iostream>
#include <string> // Tambahkan untuk menggunakan tipe data string
using namespace std;

void cetak_tanggal(int, int, int);

int main() {
    // Definisi struktur date sebagai lokal di dalam main
    struct Date {
        int month;
        int day;
        int year;
    } today;

    cout << "Enter the current date (mm-dd-yyyy): ";
    cin >> today.month >> today.day >> today.year;

    cetak_tanggal(today.month, today.day, today.year);

    return 0;
}

void cetak_tanggal(int mm, int dd, int yy) {
    // Mengganti array char dengan string
    static string nama_bulan[] = {
        "Wrong month", "January", "February", "March",
        "April", "May", "June", "July", "August",
        "September", "October", "November", "December"
    };

    cout << "Today's date is " << nama_bulan[mm] << " " << dd << ", " << yy << endl << endl;
}