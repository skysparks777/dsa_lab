
// Code:-
#include <iostream>
#include <vector>
using namespace std;

void generateParenthesisHelper(int open, int close, string current, int n, vector<string>& result) {
    if (current.length() == 2 * n) {
        result.push_back(current);
        return;
    }
    
    if (open < n) generateParenthesisHelper(open + 1, close, current + "(", n, result);
    if (close < open) generateParenthesisHelper(open, close + 1, current + ")", n, result);
}

vector<string> generateParenthesis(int n) {
    vector<string> result;
    generateParenthesisHelper(0, 0, "", n, result);
    return result;
}

int main() {
    int n = 3;
    vector<string> validParentheses = generateParenthesis(n);
    
    for (string s : validParentheses) {
        cout << s << endl;
    }
    return 0;
}
