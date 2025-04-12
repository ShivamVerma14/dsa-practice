#include <iostream>
#include <vector>
using namespace std;

void solve(string& str, int index, vector<string>& permutations) {
    if (index == str.length()) {
        permutations.push_back(str);
        return;
    }

    for (int i = index; i < str.length(); i++) {
        swap(str[index], str[i]);
        solve(str, index + 1, permutations);
        swap(str[index], str[i]);
    }
}

vector<string> find_all_permutations(string& str) {
    vector<string> permutations;
    solve(str, 0, permutations);
    return permutations;
}

int main() {
    string str = "abc";
    vector<string> permutations = find_all_permutations(str);

    for (string& s : permutations)
        cout << "'" << s << "'" << endl;

    return 0;
}