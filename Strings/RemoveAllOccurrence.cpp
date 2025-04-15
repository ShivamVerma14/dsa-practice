#include <iostream>
using namespace std;

void remove_all_occurrences(string& s, string& part) {
    int pos = s.find(part);

    if (pos == -1)
        return;

    s.erase(pos, part.length());
    remove_all_occurrences(s, part);
}

int main() {
    string s = "daabcbaabcbc";
    string part = "abc";

    remove_all_occurrences(s, part);
    cout << s;

    return 0;
}