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
            cout << "Terima kasih telah menggunakan program ini.\n";
            break;
        default:
            cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
        }
    } while (choice != 7);

    return 0;
}