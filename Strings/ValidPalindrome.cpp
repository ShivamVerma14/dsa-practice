/*
A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all
non-alphanumeric characters, it reads the same forward and backward.
Alphanumeric characters include letters and numbers.
Given a string s, return true if it is a palindrome, or false otherwise.
*/

#include <iostream>
using namespace std;

bool is_palindrome(string s) {
    int i = 0;
    int j = s.length() - 1;

    while (i < j) {
        while (i < j && !isalnum(s[i]))
            i++;

        while (i < j && !isalnum(s[j]))
            j--;

        if (tolower(s[i]) != tolower(s[j]))
            return false;

        i++;
        j--;
    }

    return true;
}

int main() {
    string s = "A man, a plan, a canal: Panama";

    if (is_palindrome(s))
        cout << "Yes";
    else
        cout << "No";

    return 0;
}