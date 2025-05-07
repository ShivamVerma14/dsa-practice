#include <iostream>
#include <stack>
using namespace std;

bool is_valid_parenthesis(string& str) {
    stack<char> s;

    for (int i = 0; i < str.length(); i++) {
        char ch = str[i];
        
        if (ch == '(' || ch == '{' || ch == '[')
            s.push(ch);
        else if (s.empty()) 
            return false;
        else {
            if (ch == ')' && s.top() == '(' || ch == '}' && s.top() == '{' || ch == ']' && s.top() == '[')
                s.pop();
            else
                return false;
        }
    }

    return s.empty();
}

int main() {
    string s = "[()]{}{[()()]()}";

    if (is_valid_parenthesis(s))
        cout << "Yes";
    else
        cout << "No";

    return 0;
}