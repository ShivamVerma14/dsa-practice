#include <iostream>
using namespace std;

bool check_equal_count(int* actual_count, int* window_count) {
    for (int i = 0; i < 26; i++)
        if (actual_count[i] != window_count[i])
            return false;
    return true;
}

bool is_included(string& s1, string& s2) {
    int actual_count[26] = {0};
    
    for (int i = 0; i < s1.length(); i++)
        actual_count[s1[i] - 'a']++;

    int i = 0;
    int window_size = s1.length();
    int window_count[26] = {0};

    while (i < window_size && i < s2.length()) {
        window_count[s2[i] - 'a']++;
        i++;
    }

    if (check_equal_count(actual_count, window_count))
        return true;
        
    while (i < s2.length() - window_size + 1) {
        window_count[s2[i - window_size] - 'a']--;
        window_count[s2[i] - 'a']++;
        i++;

        if (check_equal_count(actual_count, window_count))
            return true;
    }

    return false;
}

int main() {
    string s1 = "ab";
    string s2 = "eidbaooo";

    if (is_included(s1, s2))
        cout << "Yes";
    else
        cout << "No";

    return 0;
}