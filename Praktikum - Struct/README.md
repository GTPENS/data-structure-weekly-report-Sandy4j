## Nama    : Yoga Sandy
## NRP     : 52236000023
## Kelas   : 11 GT-A


# Praktikum 01: Overview Struktur

## 1. contoh 1 : 
### versi c:
```c
/* File program : student1.c
Mengisi field dr variabel struktur kemudian menampilkannya */
#include <stdio.h>
#include <string.h>
struct date { /* definisi global dari tipe date */
    int month;
    int day;
    int year;
};
struct student{ /* definisi global dari tipe student */
    char name[30];
    struct date birthday;
};
/* deklarasi global dari variabel mhs*/
struct student mhs;
main(){
    /* memberikan nilai kepada field dari struktur mhs */
    strcpy(mhs.name, "MUHAMMAD IHSAN");
    mhs.birthday.month = 8;
    mhs.birthday.day = 10;
    mhs.birthday.year = 1970;
    /* menampilkan isi semua field dari struktur mhs */
    printf("Name : %s\n", mhs.name);
    printf("Birthday : %d-%d-%d\n",mhs.birthday.month,
    mhs.birthday.day, mhs.birthday.year);
}
```
### versi file cpp : 
```cpp
#include <iostream>//menambahkan iostream karena akan ada output
#include <stdio.h>
#include <string.h>
#include <string>
struct date { /* definisi global dari tipe date */
    int month;
    int day;
    int year;
};
struct student{ /* definisi global dari tipe student */
    std::string name; //merubah ke tipe data string
    date birthday;// engahpus struct
};
/* deklarasi global dari variabel mhs*/
student mhs;

int main(){ //penambahan int main
    /* memberikan nilai kepada field dari struktur mhs */
    mhs.name ="MUHAMMAD IHSAN";
    mhs.birthday.month = 8;
    mhs.birthday.day = 10;
    mhs.birthday.year = 1970;
    /* menampilkan isi semua field dari struktur mhs */
    std::cout << "Name : " << mhs.name << std::endl;
    std::cout << "Birthday : " << mhs.birthday.month << "-" << mhs.birthday.day << "-" << mhs.birthday.year << std::endl;
}
```
## 2. Contoh 2 :
### Versi C : 
```c
/* File program : zodiak.c
Menentukan zodiak berdasarkan data tanggal lahir masukan */
#include <stdio.h>
main()
{
    struct zodiak {
        char nama[11];
        int tgl_awal;
        int bln_awal;
        int tgl_akhir;
        int bln_akhir;
    };
    static struct zodiak bintang = {"Sagitarius", 22, 11, 21, 12};
    int tgl_lhr, bln_lhr, thn_lhr;
    printf("Masukkan tgl lahir Anda (XX-XX-XXXX): ");
    scanf("%d-%d-%d",&tgl_lhr, &bln_lhr, &thn_lhr);
    if((tgl_lhr >= bintang.tgl_awal && bln_lhr ==
        bintang.bln_awal) || (tgl_lhr <= bintang.tgl_akhir &&
        bln_lhr == bintang.bln_akhir))
        printf("Bintang Anda adalah %s\n", bintang.nama);
    else
        printf("Bintang Anda bukan %s\n", bintang.nama);
}
```
### Versi cpp :
```cpp
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
    static Zodiak bintang = {"Sagitarius", 22, 11, 21, 12};

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
```
## 3. Contoh 3 :
### Versi c :
```c
/* File program : student2.c
Array struktur untuk menyimpan data-data student */
#include <stdio.h>
#define MAKS 20
struct date { //definisi global dr tipe date
    int month;
    int day;
    int year;
};
struct student { //definisi global dr tipe student
    char name[30];
    struct date birthday;
};
//deklarasi global dari variabel student
struct student data_mhs[MAKS];
main()
{
    int i=0, sudah_benar, jml;
    char lagi;
    //memasukkan data
    do
    {
        printf("Name : ");
        fgets(data_mhs[i].name,sizeof data_mhs[i].name,stdin);
        printf("Birthday (mm-dd-yyyy): ");
        scanf("%d-%d-%d",
        &data_mhs[i].birthday.month,
        &data_mhs[i].birthday.day,
        &data_mhs[i].birthday.year);
        printf("\n");
        i++;
        printf("Mau memasukkan data lagi [Y/T] ? ");
    do
    {
        lagi = getchar( ); //baca tombol
        sudah_benar = (lagi == 'Y') || (lagi== 'y')||
        (lagi == 'T') || (lagi == 't');
    } while(! sudah_benar);
        //hapus sisa data dalam penampung keyboard
        fflush(stdin);
        printf("\n");
    } while(lagi == 'Y' || lagi == 'y');
        jml = i;
        //menampilkan data
        printf("DATA SISWA\n");
    for (i=0; i<jml; i++)
    {
        printf("%d. Name : %s", i+1, data_mhs[i].name);
        printf(" Birthday : %d-%d-%d\n\n",
        data_mhs[i].birthday.month,
        data_mhs[i].birthday.day,
        data_mhs[i].birthday.year );
    };
}
```
### Versi cpp : 
```cpp
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
```
## 4. Contoh 4 : 
### Versi c :
```c
/* File program : cetak1.c
Melewatkan elemen struktur sbg parameter fungsi scr nilai */
#include <stdio.h>
void cetak_tanggal(int, int, int);
main()
{
   struct date { /* definisi lokal dari tipe date */
      int month;
      int day;
      int year;
   } today;

   printf("Enter the current date (mm-dd-yyyy): ");
   scanf("%d-%d-%d", &today.month, &today.day, &today.year);

   cetak_tanggal(today.month, today.day, today.year);
   }
   void cetak_tanggal(int mm, int dd, int yy)
   {
   static char *nama_bulan[] = {
   "Wrong month", "January", "February", "March",
   "April", "May", "June", "July", "August",
   "September", "October", "November", "December"
   };
   printf("Todays date is %s %d, %d\n\n",
   nama_bulan[mm],dd,yy);
} 
```
### Versi cpp : 
```cpp
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
```
## 5. Contoh 5 :
### Versi c :
```c
/* File program : posisi1.c
Melewatkan elemen struktur sbg parameter fungsi scr acuan */
#include <stdio.h>
void tukar_xy(int *, int *);
main()
{
    struct koordinat {
        int x;
        int y;
    } posisi;
    printf("Masukkan koordinat posisi (x, y) : ");
    scanf("%d, %d", &posisi.x, &posisi.y);
    printf("x, y semula = %d, %d\n", posisi.x, posisi.y);
    tukar_xy(&posisi.x, &posisi.y);
    printf("x, y sekarang = %d, %d\n", posisi.x, posisi.y);
}
void tukar_xy(int *a, int *b)
{
    int z;
    z = *a;
    *a = *b;
    *b = z;
} 
```
### Versi cpp :
```cpp
#include <iostream>
#include <string> // Tambahkan untuk menggunakan tipe data string
using namespace std;

void tukar_xy(int *, int *);

int main() {
    // Definisi struktur koordinat sebagai lokal di dalam main
    struct Koordinat {
        int x;
        int y;
    } posisi;

    cout << "Masukkan koordinat posisi (x, y): ";
    cin >> posisi.x >> posisi.y;
    cout << "x, y semula = " << posisi.x << ", " << posisi.y << endl;

    tukar_xy(&posisi.x, &posisi.y);

    cout << "x, y sekarang = " << posisi.x << ", " << posisi.y << endl;

    return 0;
}

void tukar_xy(int *a, int *b) {
    int z;
    z = *a;
    *a = *b;
    *b = z;
}
```
## 6. Contoh 6 :
### Versi c :
```c
/* File program : cetak2.c
Melewatkan struktur sebagai parameter fungsi */
#include <stdio.h>
struct date { /* definisi global dari tipe date */
    int month;
    int day;
    int year;
};
void cetak_tanggal(struct date);
main()
{
    struct date today;

    printf("Enter the current date (mm-dd-yyyy): ");
    scanf("%d-%d-%d", &today.month, &today.day, &today.year);
    cetak_tanggal(today);
}
void cetak_tanggal(struct date now)
{
    static char *nama_bulan[] = {
    "Wrong month", "January", "February", "March",
    "April", "May", "June", "July", "August",
    "September", "October", "November", "December"
    };
    printf("Todays date is %s %d, %d\n\n",
    nama_bulan[now.month], now.day, now.year);
} 
```
### Versi cpp :
```cpp
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
```
## 7. Contoh 7 :
### Versi C :
```c
/* File program : posisi2.c
Fungsi parameternya berupa pointer yg menunjuk ke struktur */
#include <stdio.h>
struct koordinat
{
    int x;
    int y;
};
void tukar_xy(struct koordinat *);
main()
{
    struct koordinat posisi;
    printf("Masukkan koordinat posisi (x, y) : ");
    scanf("%d, %d", &posisi.x, &posisi.y);
    printf("x, y semula = %d, %d\n", posisi.x, posisi.y);
    tukar_xy(&posisi);
    printf("x, y sekarang = %d, %d\n", posisi.x, posisi.y);
}
void tukar_xy(struct koordinat *pos_xy)
{
    int z;
    z = (*pos_xy).x;
    (*pos_xy).x = (*pos_xy).y;
    (*pos_xy).y = z;
}
```
### Versi cpp :
```cpp
#include <iostream>
using namespace std;

// Definisikan struktur koordinat sebagai global
struct Koordinat {
    int x;
    int y;
};

// Deklarasi fungsi tukar_xy dengan parameter bertipe pointer ke Koordinat
void tukar_xy(Koordinat *);

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
void tukar_xy(Koordinat *pos_xy) {
    int z;
    z = pos_xy->x;
    pos_xy->x = pos_xy->y;
    pos_xy->y = z;
}
```

# Latihan Soal Tugas Praktikum
```cpp
// 1. Definisikan sebuah struktur (misalkan namanya = record) yang memiliki 3 buah
// field berupa sebuah integer (misalkan namanya = loop), sebuah array karakter
// dengan 5 elemen (misalkan namanya = word) dan sebuah float (misalkan namanya
// = sum). 

#include <iostream>
using namespace std;

struct record{
    int loop;
    string word;
    float sum;
};

int main(){
    //2. Deklarasikan sebuah variabel struktur (misalkan namanya = sample)
    //yang didefinisikan memiliki tipe struktur record. 
    record sample={1, "Hatfan", 14.57f};

    return 0;
}
```