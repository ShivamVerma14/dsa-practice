/*
You are given a string s consisting of lowercase English letters. A duplicate removal consists of choosing
two adjacent and equal letters and removing them.
We repeatedly make duplicate removals on s until we no longer can.
Return the final string after all such duplicate removals have been made. It can be proven that the answer is
unique.
*/

#include <iostream>
using namespace std;

string remove_duplicates(string& s) {
    string ans = "";
    for (char& ch : s) {
        if (!ans.empty() && ans.back() == ch)
            ans.pop_back();
        else
            ans.push_back(ch);
    }
    return ans;
}

int main() {
    string s = "azxxzy";
    string ans = remove_duplicates(s);

    cout << ans;
    return 0;
}