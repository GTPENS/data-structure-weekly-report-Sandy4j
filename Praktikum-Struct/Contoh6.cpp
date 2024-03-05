#include <iostream>
#include <string> // Tambahkan untuk menggunakan tipe data string
using namespace std;

// Definisikan struktur date sebagai global
struct Date {
    int month;
    int day;
    int year;
};

// Deklarasi fungsi cetak_tanggal dengan parameter bertipe Date
void cetak_tanggal(Date);

int main() {
    // Gunakan struktur Date
    Date today;

    cout << "Enter the current date (mm-dd-yyyy): ";
    cin >> today.month >> today.day >> today.year;

    cetak_tanggal(today);

    return 0;
}

// Implementasi fungsi cetak_tanggal dengan parameter bertipe Date
void cetak_tanggal(Date now) {
    // Mengganti array char dengan string
    static string nama_bulan[] = {
        "Wrong month", "January", "February", "March",
        "April", "May", "June", "July", "August",
        "September", "October", "November", "December"
    };

    cout << "Today's date is " << nama_bulan[now.month] << " " << now.day << ", " << now.year << endl << endl;
}