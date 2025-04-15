/*
Given a character array s, reverse the order of the words.
The code must solve the problem in-place, i.e. without allocating extra space.
*/

#include <iostream>
#include <vector>
using namespace std;

void reverse(vector<char>& s, int beg, int end) {
    while (beg < end) {
        swap(s[beg], s[end]);
        beg++;
        end--;
    }
}

void reverse_words(vector<char>& s) {
    reverse(s, 0, s.size() - 1);

    int beg = 0, end = 0;
    while (end < s.size()) {
        while (end < s.size() && s[end] != ' ')
            end++;

        reverse(s, beg, end - 1);

        while (end < s.size() && s[end] == ' ')
            end++;

        beg = end;
    }
}

int main() {
    vector<char> s = {'t', 'h', 'e', ' ', 's', 'k', 'y', ' ', 'i', 's', ' ', 'b', 'l', 'u', 'e'};
    reverse_words(s);

    for (char& ch : s)
        cout << ch;

    return 0;
}