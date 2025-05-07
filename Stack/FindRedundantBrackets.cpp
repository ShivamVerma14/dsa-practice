/*
Given valid mathematical expressions in the form of a string.
You are supposed to return true if the given expression contains
a pair of redundant brackets, else return false. The given string
only contains '(', ')', '+', '-', '*', '/' and lowercase english
alphabets.
*/

#include <iostream>
#include <stack>
using namespace std;

bool has_redundant_brackets(string& exp) {
    stack<char> s;

    for (int i = 0; i < exp.length(); i++) {
        char ch = exp[i];
        
        if (ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/')
            s.push(ch);

        else if (ch == ')') {
            bool is_redundant = true;
            while (!s.empty() && s.top() != '(') {
                s.pop();
                is_redundant = false;
            }

            if (is_redundant)
                return true;
            
            s.pop();
        }
    }

    return false;
}

int main() {
    string s = "(a+b+((c/d)))";

    if (has_redundant_brackets(s))
        cout << "Yes";
    else
        cout << "No";

    return 0;
}