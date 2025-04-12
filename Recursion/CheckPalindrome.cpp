#include <iostream>
using namespace std;

bool is_palindrome(string& s, int beg, int end) {
    if (beg >= end)
        return true;

    if (s[beg] != s[end])
        return false;

    return is_palindrome(s, beg + 1, end - 1);
}

int main() {
    string s = "racecar";

    if (is_palindrome(s, 0, s.length() - 1))
        cout << "Yes";
    else
        cout << "No";

    return 0;
}