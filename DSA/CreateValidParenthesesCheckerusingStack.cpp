// ## Problem Statement
// Check if a string containing brackets is valid (properly opened and closed).

// ## Task
// - Use stack data structure
// - Support (), {}, [] brackets
// - Return true/false

// ## Example
// Input: "({[]})"
// Output: true

// Input: "({[})"
// Output: false


#include <iostream>
#include <stack>
#include <string>
using namespace std;

// Function to check if parentheses are valid
bool isValid(string s) {
    stack<char> st;
    for (char c : s) {
        // Push opening brackets onto stack
        if (c == '(' || c == '{' || c == '[')
            st.push(c);
        else {
            // If stack is empty or brackets don't match, return false
            if (st.empty()) return false;
            char top = st.top();
            if ((c == ')' && top != '(') ||
                (c == '}' && top != '{') ||
                (c == ']' && top != '['))
                return false;
            st.pop(); // Pop matched opening bracket
        }
    }
    // Stack should be empty if all brackets matched
    return st.empty();
}

int main() {
    string s1 = "({[]})";
    string s2 = "({[})";
    cout << boolalpha << isValid(s1) << endl; // true
    cout << boolalpha << isValid(s2) << endl; // false
    return 0;
}
