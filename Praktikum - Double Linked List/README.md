## Nama    : Yoga Sandy
## NRP     : 52236000023
## Kelas   : 11 GT-A

# Praktikum 03: Overview Double Linked List


1. Fungsi ini digunakan untuk menyisipkan node baru di awal linked list. 
```cpp
void insertAtStart(string name, int nrp) {
    Node* newNode = new Node;
    newNode->name = name;
    newNode->nrp = nrp;
    newNode->next = head;
    newNode->prev = NULL;

    if (head == NULL) {
        tail = newNode;
    }
    else {
        head->prev = newNode;
    }

    head = newNode;
}
```

2. Fungsi ini digunakan untuk menyisipkan node baru di akhir linked list.
```cpp
void insertAtEnd(string name, int nrp) {
    Node* newNode = new Node;
    newNode->name = name;
    newNode->nrp = nrp;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (head == NULL) {
        head = newNode;
        tail = newNode;
    }
    else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}
```

3. Fungsi displayLIFO digunakan untuk menampilkan data dalam double linked list dengan prinsip LIFO (Last In First Out).
```cpp
void displayLIFO() {
    Node* temp = tail;
    cout << "Data dalam Double Linked List (LIFO): " << endl;
    while (temp != NULL) {
        cout << "Nama: " << temp->name << ", NRP: " << temp->nrp << endl;
        temp = temp->prev;
    }
}
```

4. Fungsi displayFIFO digunakan untuk menampilkan data dalam double linked list dengan prinsip FIFO (First In First Out).
```cpp
void displayFIFO() {
    Node* temp = head;
    cout << "Data dalam Double Linked List (FIFO): " << endl;
    while (temp != NULL) {
        cout << "Nama: " << temp->name << ", NRP: " << temp->nrp << endl;
        temp = temp->next;
    }
}
```

5. Fungsi ini digunakan untuk mencari node dengan nama tertentu dalam linked list. Ia menginisialisasi sebuah pointer temp dengan head, kemudian melakukan iterasi hingga akhir linked list atau menemukan node dengan nama yang dicari. 
```cpp
Node* searchNode(string name) {
    Node* temp = head;
    while (temp != NULL) {
        if (temp->name == name) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}
```

6. Fungsi ini digunakan untuk menghapus node dengan nama tertentu dari linked list. Pertama, ia memanggil fungsi searchNode untuk mencari node yang ingin dihapus. Jika node tidak ditemukan, maka fungsi akan menampilkan pesan dan keluar. Jika node ditemukan, maka terdapat kondisi khusus jika node yang dihapus adalah node pertama atau node terakhir. 
```cpp
void deleteNode(string name) {
    Node* temp = searchNode(name);
    if (temp == NULL) {
        cout << "Node dengan nama " << name << " tidak ditemukan." << endl;
        return;
    }

    if (temp == head) {
        head = temp->next;
        if (head != NULL) {
            head->prev = NULL;
        }
        else {
            tail = NULL;
        }
    }
    else if (temp == tail) {
        tail = temp->prev;
        tail->next = NULL;
    }
    else {
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
    }

    delete temp;
    cout << "Node dengan nama " << name << " berhasil dihapus." << endl;
}
```



7. Versi Lengkap dari gabungan semua fungsi ditambah dengan menu pilihan.
```cpp
#include <iostream>
#include <string>
using namespace std;

struct Node {
    string name;
    int nrp;
    Node* next;
    Node* prev;
};

Node* head = NULL;
Node* tail = NULL;

//Menyisipkan Node Di Awal Linked List
void insertAtStart(string name, int nrp) {
    Node* newNode = new Node;
    newNode->name = name;
    newNode->nrp = nrp;
    newNode->next = head;
    newNode->prev = NULL;

    if (head == NULL) {
        tail = newNode;
    }
    else {
        head->prev = newNode;
    }

    head = newNode;
}

//Menyisipkan Node Di Akhir Linked List
void insertAtEnd(string name, int nrp) {
    Node* newNode = new Node;
    newNode->name = name;
    newNode->nrp = nrp;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (head == NULL) {
        head = newNode;
        tail = newNode;
    }
    else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

// Menampilkan Data LIFO Dalam Linked List
void displayLIFO() {
    Node* temp = tail;
    cout << "Data dalam Double Linked List (LIFO): " << endl;
    while (temp != NULL) {
        cout << "Nama: " << temp->name << ", NRP: " << temp->nrp << endl;
        temp = temp->prev;
    }
}

// Menampilkan Data FIFO Dalam Linked List
void displayFIFO() {
    Node* temp = head;
    cout << "Data dalam Double Linked List (FIFO): " << endl;
    while (temp != NULL) {
        cout << "Nama: " << temp->name << ", NRP: " << temp->nrp << endl;
        temp = temp->next;
    }
}

//Mencari Node Tertentu Dalam Linked List
Node* searchNode(string name) {
    Node* temp = head;
    while (temp != NULL) {
        if (temp->name == name) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

//Menghapus Node Tertentu Dalam Linked List 
void deleteNode(string name) {
    Node* temp = searchNode(name);
    if (temp == NULL) {
        cout << "Node dengan nama " << name << " tidak ditemukan." << endl;
        return;
    }

    if (temp == head) {
        head = temp->next;
        if (head != NULL) {
            head->prev = NULL;
        }
        else {
            tail = NULL;
        }
    }
    else if (temp == tail) {
        tail = temp->prev;
        tail->next = NULL;
    }
    else {
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
    }

    delete temp;
    cout << "Node dengan nama " << name << " berhasil dihapus." << endl;
}

int main() {
    int choice;
    string name;
    int nrp;
    Node* found = NULL;

    do {
        cout << "\nMenu Operasi Double Linked List:" << endl;
        cout << "1. Menyisipkan simpul di awal" << endl;
        cout << "2. Menyisipkan simpul di akhir" << endl;
        cout << "3. Menampilkan data (LIFO)" << endl;
        cout << "4. Menampilkan data (FIFO)" << endl;
        cout << "5. Mencari simpul" << endl;
        cout << "6. Menghapus simpul" << endl;
        cout << "7. Keluar" << endl;
        cout << "Masukkan pilihan: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Masukkan nama: ";
            cin >> name;
            cout << "Masukkan NRP: ";
            cin >> nrp;
            insertAtStart(name, nrp);
            break;
        case 2:
            cout << "Masukkan nama: ";
            cin >> name;
            cout << "Masukkan NRP: ";
            cin >> nrp;
            insertAtEnd(name, nrp);
            break;
        case 3:
            displayLIFO();
            break;
        case 4:
            displayFIFO();
            break;
        case 5:
            cout << "Masukkan nama yang ingin dicari: ";
            cin >> name;
            found = searchNode(name);
            if (found == NULL) {
                cout << "Node dengan nama " << name << " tidak ditemukan." << endl;
            }
            else {
                cout << "Node ditemukan: " << endl;
                cout << "Nama: " << found->name << ", NRP: " << found->nrp << endl;
            }
            break;
        case 6:
            cout << "Masukkan nama yang ingin dihapus: ";
            cin >> name;
            deleteNode(name);
            break;
        case 7:
            cout << "Terima kasih!" << endl;
            break;
        default:
            cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
        }
    } while (choice != 7);

    return 0;
}
```
