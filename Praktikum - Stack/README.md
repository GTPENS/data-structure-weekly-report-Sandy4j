
## Nama    : Yoga Sandy
## NRP     : 52236000023
## Kelas   : 11 GT-A

# Praktikum 04: Overview Stack

1. **Implementasikan Stack Menggunakan Linked List**

Kelas  `ListStack`  merupakan implementasi Stack, dengan menggunakan operasi dasar seperti  `push`  (menambahkan elemen ke Stack),  
`pop`  (menghapus elemen dari Stack),  `peek`  (melihat elemen teratas tanpa menghapusnya),  
`size`  (mendapatkan ukuran Stack), dan  `empty`  (memeriksa apakah Stack kosong).

```cpp
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
```

2. **Memeriksa Keseimbangan Tanda Kurung**

Memeriksa keseimbangan tanda kurung dalam sebuah ekspresi menggunakan Stack dengan mendorong tanda kurung pembuka ke dalam Stack dan mencocokkannya dengan tanda kurung penutup.
```cpp
#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isBalancedParenthesis(const string& expr) {
    stack<char> stack;

    for (char ch : expr) {
        switch (ch) {
            case '(':
            case '[':
            case '{':
                stack.push(ch);
                break;
            case ')':
                if (stack.empty() || stack.top() != '(') {
                    return false;
                }
                stack.pop();
                break;
            case ']':
                if (stack.empty() || stack.top() != '[') {
                    return false;
                }
                stack.pop();
                break;
            case '}':
                if (stack.empty() || stack.top() != '{') {
                    return false;
                }
                stack.pop();
                break;
            default:
                break;
        }
    }

    return stack.empty();
}

int main() {
    string expr1 = "{()}";
    string expr2 = "{())}";

    cout << "Expression: " << expr1 << " is "
         << (isBalancedParenthesis(expr1) ? "balanced" : "not balanced") << endl;
    cout << "Expression: " << expr2 << " is "
         << (isBalancedParenthesis(expr2) ? "balanced" : "not balanced") << endl;

    return 0;
}
```

3. **Konversi Infix ke Postfix**

Mengonversi ekspresi matematis dari notasi infix ke postfix menggunakan Stack untuk menangani prioritas operator sesuai dengan aturan precedence.
```cpp
#include <iostream>
#include <stack>
#include <string>
#include <cctype>
using namespace std;

bool isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}

int precedence(char op) {
    if (op == '+' || op == '-') {
        return 1;
    } else if (op == '*' || op == '/') {
        return 2;
    }
    return 0;
}

string infixToPostfix(const string& infix) {
    stack<char> stack;
    string postfix;

    for (char ch : infix) {
        if (isalnum(ch)) {
            postfix += ch;
        } else if (ch == '(') {
            stack.push(ch);
        } else if (ch == ')') {
            while (!stack.empty() && stack.top() != '(') {
                postfix += stack.top();
                stack.pop();
            }
            if (!stack.empty() && stack.top() == '(') {
                stack.pop();
            }
        } else {
            while (!stack.empty() && precedence(ch) <= precedence(stack.top())) {
                postfix += stack.top();
                stack.pop();
            }
            stack.push(ch);
        }
    }

    while (!stack.empty()) {
        postfix += stack.top();
        stack.pop();
    }

    return postfix;
}

int main() {
    string infix = "a+b*(c^d-e)^(f+g*h)-i";
    string postfix = infixToPostfix(infix);

    cout << "Infix expression: " << infix << endl;
    cout << "Postfix expression: " << postfix << endl;

    return 0;
}
```

4. **Konversi Infix ke Prefix**

Mengonversi ekspresi matematis dari notasi infix ke prefix dengan membalik ekspresi infix, mengonversinya ke postfix, lalu membalik kembali hasilnya.
```cpp
#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
#include <cctype>
using namespace std;

int precedence(char op) {
    if (op == '+' || op == '-') {
        return 1;
    } else if (op == '*' || op == '/') {
        return 2;
    } else if (op == '^') {
        return 3;
    }
    return 0;
}

string infixToPrefix(const string& infix) {
    string reversedInfix = infix;
    reverse(reversedInfix.begin(), reversedInfix.end());

    for (int i = 0; i < reversedInfix.length(); i++) {
        if (reversedInfix[i] == '(') {
            reversedInfix[i] = ')';
        } else if (reversedInfix[i] == ')') {
            reversedInfix[i] = '(';
        }
    }

    stack<char> stack;
    string prefix;

    for (char ch : reversedInfix) {
        if (isalnum(ch)) {
            prefix += ch;
        } else if (ch == ')') {
            stack.push(ch);
        } else if (ch == '(') {
            while (!stack.empty() && stack.top() != ')') {
                prefix += stack.top();
                stack.pop();
            }
            if (!stack.empty() && stack.top() == ')') {
                stack.pop();
            }
        } else {
            while (!stack.empty() && stack.top() != ')' &&
                   ((ch != '^' && precedence(ch) <= precedence(stack.top())) ||
                    (ch == '^' && precedence(ch) < precedence(stack.top())))) {
                prefix += stack.top();
                stack.pop();
            }
            stack.push(ch);
        }
    }

    while (!stack.empty()) {
        prefix += stack.top();
        stack.pop();
    }

    reverse(prefix.begin(), prefix.end());
    return prefix;
}

int main() {
    string infix = "a+b*(c^d-e)^(f+g*h)-i";
    string prefix = infixToPrefix(infix);

    cout << "Infix expression: " << infix << endl;
    cout << "Prefix expression: " << prefix << endl;

    return 0;
}
```

5. **Evaluasi Ekspresi Postfix**

Mengevaluasi ekspresi postfix dengan mendorong operand ke dalam Stack dan melakukan operasi aritmatika sesuai operator yang ditemukan
```cpp
#include <iostream>
#include <stack>
#include <string>
#include <cctype>
using namespace std;

int evaluatePostfix(const string& postfix) {
    stack<int> stack;

    for (char ch : postfix) {
        if (isdigit(ch)) {
            stack.push(ch - '0');
        } else {
            int operand2 = stack.top();
            stack.pop();
            int operand1 = stack.top();
            stack.pop();

            switch (ch) {
                case '+':
                    stack.push(operand1 + operand2);
                    break;
                case '-':
                    stack.push(operand1 - operand2);
                    break;
                case '*':
                    stack.push(operand1 * operand2);
                    break;
                case '/':
                    stack.push(operand1 / operand2);
                    break;
            }
        }
    }

    return stack.top();
}

int main() {
    string postfix = "83+72*-";
    int result = evaluatePostfix(postfix);

    cout << "Postfix expression: " << postfix << endl;
    cout << "Result: " << result << endl;

    return 0;
}
```

6. **Palindrome String menggunakan Stack**

Untuk memeriksa apakah sebuah string merupakan palindrome atau tidak dengan membandingkan setengah karakter pertama yang didorong ke dalam Stack dengan setengah karakter kedua.
```cpp
#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;

bool isPalindrome(const string& str) {
    stack<char> stack;
    string temp = str;

    // Menghapus spasi dan mengubah ke huruf kecil
    temp.erase(remove_if(temp.begin(), temp.end(), ::isspace), temp.end());
    transform(temp.begin(), temp.end(), temp.begin(), ::tolower);

    // Mendorong setengah karakter ke dalam stack
    for (int i = 0; i < temp.length() / 2; i++) {
        stack.push(temp[i]);
    }

    // Memulai dari tengah (atau tengah + 1 jika panjang ganjil)
    int start = temp.length() % 2 == 0 ? temp.length() / 2 : (temp.length() / 2) + 1;

    // Memastikan karakter yang sesuai dengan stack
    for (int i = start; i < temp.length(); i++) {
        if (temp[i] != stack.top()) {
            return false;
        }
        stack.pop();
    }

    return true;
}

int main() {
    string str;
    cout << "Masukkan sebuah string: ";
    getline(cin, str);

    cout << "\"" << str << "\" is " << (isPalindrome(str) ? "a palindrome" : "not a palindrome") << endl;

    return 0;
}
```


