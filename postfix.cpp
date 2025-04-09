
#include <iostream>
#include <stack>
using namespace std;

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;
}

string infixToPostfix(string expr) {
    stack<char> s;
    string output = "";

    for (char ch : expr) {
        if (isalnum(ch)) {
            output += ch;  // Append operand
        } else if (ch == '(') {
            s.push(ch);
        } else if (ch == ')') {
            while (!s.empty() && s.top() != '(') {
                output += s.top(); s.pop();
            }
            s.pop(); // Pop '('
        } else {
            while (!s.empty() && precedence(s.top()) >= precedence(ch)) {
                output += s.top(); s.pop();
            }
            s.push(ch);
        }
    }

    while (!s.empty()) {
        output += s.top(); s.pop();
    }

    return output;
}

int main() {
    string infix = "A+B*(C^D-E)";
    cout << "Postfix: " << infixToPostfix(infix) << endl;
    return 0;
}
