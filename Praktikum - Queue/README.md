
## Nama    : Yoga Sandy
## NRP     : 52236000023
## Kelas   : 11 GT-A

# Praktikum 05: Overview Queue

1. **Queue Menggunakan Linked List**

Program ini mengimplementasikan struktur data Queue menggunakan Linked List.

```cpp
#include <iostream>
using namespace std;

class Queue {
private:
    struct Node {
        int value;
        Node* next;
        Node(int v, Node* n) : value(v), next(n) {}
    };

    Node* head = nullptr;
    Node* tail = nullptr;
    int count = 0;

public:
    int size() { return count; }
    bool empty() { return count == 0; }

    void print() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->value << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    int peek() {
        if (empty()) {
            throw invalid_argument("QueueEmptyException");
        }
        return head->value;
    }

    void enqueue(int value) {
        Node* temp = new Node(value, nullptr);
        if (head == nullptr) {
            head = tail = temp;
        } else {
            tail->next = temp;
            tail = temp;
        }
        count++;
    }

    int dequeue() {
        if (empty()) {
            throw invalid_argument("QueueEmptyException");
        }
        int value = head->value;
        Node* temp = head;
        head = head->next;
        delete temp;
        count--;
        return value;
    }
};

int main() {
    Queue q;
    for (int i = 1; i <= 100; i++) {
        q.enqueue(i);
    }
    for (int i = 1; i <= 50; i++) {
        q.dequeue();
    }
    q.print();
    return 0;
}
```

2. **Enqueue pada Queue Linked List**

Program ini hanya memuat implementasi metode  `enqueue`  untuk menambahkan elemen baru ke akhir Queue Linked List.
```cpp
void Queue::enqueue(int value) {
    Node* temp = new Node(value, nullptr);
    if (head == nullptr) {
        head = tail = temp;
    } else {
        tail->next = temp;
        tail = temp;
    }
    count++;
}
```

3. **Dequeue pada Queue Linked List**

Program ini hanya memuat implementasi metode  `dequeue`  untuk menghapus elemen dari awal Queue Linked List.
```cpp
int Queue::dequeue() {
    if (empty()) {
        throw invalid_argument("QueueEmptyException");
    }
    int value = head->value;
    Node* temp = head;
    head = head->next;
    delete temp;
    count--;
    return value;
}
```

4. **Implementasi Queue menggunakan 2 Stack**

Program ini mengimplementasikan struktur data Queue menggunakan dua buah Stack.
```cpp
#include <iostream>
#include <stack>
using namespace std;

class QueueUsingStack {
private:
    stack<int> stk1, stk2;

public:
    void enqueue(int value) {
        stk1.push(value);
    }

    int dequeue() {
        int value;
        if (stk2.empty()) {
            while (!stk1.empty()) {
                value = stk1.top();
                stk1.pop();
                stk2.push(value);
            }
        }
        if (stk2.empty()) {
            throw invalid_argument("QueueEmptyException");
        }
        value = stk2.top();
        stk2.pop();
        return value;
    }
};

int main() {
    QueueUsingStack que;
    que.enqueue(1);
    que.enqueue(11);
    que.enqueue(111);
    cout << que.dequeue() << endl;  // Output: 1
    que.enqueue(2);
    que.enqueue(21);
    que.enqueue(211);
    cout << que.dequeue() << endl;  // Output: 11
    cout << que.dequeue() << endl;  // Output: 111
    return 0;
}
```

## Tugas

**1. Stack using a Queue**
Pada permasalahan ini, kita harus mengimplementasikan struktur data Stack menggunakan struktur data Queue. Salah satu solusi yang diberikan adalah dengan menggunakan satu antrian (queue) saja.
```cpp
#include <iostream>
#include <queue>
using namespace std;

class StackUsingQueue {
private:
    queue<int> q;

public:
    void push(int value) {
        int size = q.size();
        q.push(value);

        // Memindahkan elemen-elemen lain ke belakang
        for (int i = 0; i < size; i++) {
            q.push(q.front());
            q.pop();
        }
    }

    void pop() {
        if (q.empty()) {
            throw out_of_range("Stack is empty");
        }
        q.pop();
    }

    int top() {
        if (q.empty()) {
            throw out_of_range("Stack is empty");
        }
        return q.front();
    }

    bool empty() {
        return q.empty();
    }
};

int main() {
    StackUsingQueue stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);

    cout << "Top: " << stack.top() << endl; 

    stack.pop();

    cout << "Top: " << stack.top() << endl;

    return 0;
}
```
**2. Josephus problem**
Pada permasalahan Josephus, kita harus menemukan posisi di mana seseorang harus berdiri dalam sebuah antrian agar dapat mendapatkan kebebasan. Setiap langkah, k orang dihapus dari antrian, dan kemudian ditambahkan kembali satu per satu ke antrian
```cpp
#include <iostream>
#include <list>
using namespace std;

int josephus(int n, int k) {
    list<int> people;

    // Membuat daftar orang dari 1 hingga n
    for (int i = 1; i <= n; i++) {
        people.push_back(i);
    }

    auto it = people.begin();
    while (people.size() > 1) {
        // Memindahkan iterator k-1 langkah
        for (int i = 0; i < k - 1; i++) {
            it++;
            if (it == people.end()) {
                it = people.begin();
            }
        }

        // Menghapus orang saat ini
        auto next = it;
        next++;
        if (next == people.end()) {
            next = people.begin();
        }
        it = people.erase(it);
        it = next;
    }

    return people.front();
}

int main() {
    int n, k;
    cout << "Masukkan jumlah orang: ";
    cin >> n;
    cout << "Masukkan nilai k: ";
    cin >> k;

    int survivor = josephus(n, k);
    cout << "Orang yang selamat adalah: " << survivor << endl;

    return 0;
}
```