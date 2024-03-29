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