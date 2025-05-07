#include <iostream>
#include <stack>
using namespace std;

string reverse(string str) {
    stack<char> s;

    for (int i = 0; i < str.length(); i++)
        s.push(str[i]);

    string ans = "";

    while (!s.empty()) {
        ans += s.top();
        s.pop();
    }

    return ans;
}

int main() {
    string s = "shivam";
    
    string ans = reverse(s);
    cout << ans;

    return 0;
}