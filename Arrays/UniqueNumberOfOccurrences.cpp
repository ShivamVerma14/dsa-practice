/*
Given an array of integers 'arr', return 'true' if the number of occurrences of each value in the array is unique, or 'false'
otherwise.
*/

#include <bits/stdc++.h>
using namespace std;

bool has_unique_occurrences(vector<int>& arr) {
    unordered_map<int, int> freq;
    for (int& num : arr)
        freq[num]++;

    unordered_set<int> occurrences;
    for (auto& [element, count] : freq) {
        if (occurrences.find(count) != occurrences.end())
            return false;
        occurrences.insert(count);
    }

    return true;
}

int main() {
    vector<int> arr = {1, 2, 2, 1, 1, 3};

    if (has_unique_occurrences(arr))
        cout << "Yes";
    else
        cout << "No";

    return 0;
}