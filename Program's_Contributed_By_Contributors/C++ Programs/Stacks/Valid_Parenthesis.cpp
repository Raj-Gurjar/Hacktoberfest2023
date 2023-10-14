#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;  // Initialize a stack to keep track of open brackets.

        for (auto &i : s) {
            if (i == '(' || i == '{' || i == '[') {  // If an open bracket is encountered, push it onto the stack.
                stk.push(i);
            } else {
                if (stk.empty()) {
                    return false;  // If a closing bracket is encountered with an empty stack, the string is not valid.
                }

                if ((i == ')' && stk.top() == '(') || (i == '}' && stk.top() == '{') ||
                    (i == ']' && stk.top() == '[')) {
                    stk.pop();  // If a matching closing bracket is found, pop the corresponding open bracket from the stack.
                } else {
                    return false;  // If a mismatch is found, the string is not valid.
                }
            }
        }

        return stk.empty();  // If the stack is empty at the end, the string is valid.
    }
};

int main() {
    Solution solution;
    string input;

    cout << "Enter a string with brackets( '(', ')', '{', '}', '[' and ']' ): ";
    cin >> input;

    if (solution.isValid(input)) {
        cout << "The string is valid." << endl;
    } else {
        cout << "The string is not valid." << endl;
    }

    return 0;
}
