

#include <iostream>
#include <stack>
#include <cctype>

using namespace std;

// Function to check if a character is an operator
bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

// Function to convert Prefix to Postfix
string prefixToPostfix(string prefix) {
    stack<string> s;
    int length = prefix.length();

    // Traverse the prefix expression from right to left
    for (int i = length - 1; i >= 0; i--) {
        // If character is an operand, push it to stack
        if (isalnum(prefix[i])) {
            string operand(1, prefix[i]);
            s.push(operand);
        }
        // If character is an operator
        else if (isOperator(prefix[i])) {
            // Pop two operands from stack
            string op1 = s.top(); s.pop();
            string op2 = s.top(); s.pop();

            // Form the postfix expression: operand1 operand2 operator
            string postfixExp = op1 + op2 + prefix[i];

            // Push result back to stack
            s.push(postfixExp);
        }
    }

    // The final postfix expression is on top of the stack
    return s.top();
}

// Main function
int main() {
    string prefixExp = "*+AB-CD"; // Example input
    cout << "Prefix Expression: " << prefixExp << endl;

    string postfixExp = prefixToPostfix(prefixExp);
    cout << "Postfix Expression: " << postfixExp << endl;

    return 0;
}
