#include <iostream>
using namespace std;

class Node {
public:
    int value;
    Node* next;

    Node(int val, Node* n = nullptr) {
        value = val;
        next = n;
    }
};

class ListStack {
private:
    Node* head;
    int count;

public:
    ListStack() {
        head = nullptr;
        count = 0;
    }

    int size() {
        return count;
    }

    bool empty() {
        return count == 0;
    }

    int peek() {
        if (empty()) {
            throw out_of_range("Stack is empty");
        }
        return head->value;
    }

    void push(int value) {
        head = new Node(value, head);
        count++;
    }

    int pop() {
        if (empty()) {
            throw out_of_range("Stack is empty");
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
    ListStack stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);

    cout << "Top element: " << stack.peek() << endl;
    cout << "Size of stack: " << stack.size() << endl;

    stack.pop();
    cout << "Top element after pop: " << stack.peek() << endl;

    return 0;
}