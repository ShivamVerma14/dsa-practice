#include <iostream>
#include <vector>
using namespace std;

void solve(string& digits, int index, string output, vector<string>& combinations, vector<string>& mappings) {
    if (index == digits.length()) {
        combinations.push_back(output);
        return;
    }

    int digit = digits[index] - '0';
    string value = mappings[digit];

    for (int i = 0; i < value.length(); i++) {
        output.push_back(value[i]);
        solve(digits, index + 1, output, combinations, mappings);
        output.pop_back();
    }
}

vector<string> letter_combinations(string& digits) {
    vector<string> combinations;
    vector<string> mappings = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    solve(digits, 0, "", combinations, mappings);
    return combinations;
} 

int main() {
    string digits = "23";
    vector<string> combinations = letter_combinations(digits);

    for (string& s : combinations)
        cout << "'" << s << "'" << endl;

    return 0;
}