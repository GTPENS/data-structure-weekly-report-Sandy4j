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
    cout << que.dequeue() << endl; 
    que.enqueue(2);
    que.enqueue(21);
    que.enqueue(211);
    cout << que.dequeue() << endl; 
    cout << que.dequeue() << endl;  
    return 0;
}