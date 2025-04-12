#include <iostream>
#include <vector>
using namespace std;

void solve(string& str, int index, string output, vector<string>& subsequences) {
    if (index == str.length()) {
        subsequences.push_back(output);
        return;
    }

    solve(str, index + 1, output, subsequences);
    solve(str, index + 1, output + str[index], subsequences);
}

vector<string> find_subsequences(string& str) {
    vector<string> subsequences;
    solve(str, 0, "", subsequences);
    return subsequences;
}

int main() {
    string str = "abc";
    vector<string> subsequences = find_subsequences(str);

    for (string& s : subsequences)
        cout << "'" << s << "'" << endl;

    return 0;
}