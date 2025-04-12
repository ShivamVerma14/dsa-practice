#include <iostream>
#include <vector>
using namespace std;

int find_first_occurrence(const vector<int>& arr, int key) {
    int beg = 0, end = arr.size() - 1;
    int ans = -1;

    while (beg <= end) {
        int mid = beg + (end - beg) / 2;

        if (arr[mid] == key) {
            ans = mid;
            end = mid - 1;
        } 
        else if (arr[mid] < key)
            beg = mid + 1;
        else
            end = mid - 1;
    }

    return ans;
}

int find_last_occurrence(const vector<int>& arr, int key) {
    int beg = 0, end = arr.size() - 1;
    int ans = -1;

    while (beg <= end) {
        int mid = beg + (end - beg) / 2;

        if (arr[mid] == key) {
            ans = mid;
            beg = mid + 1;
        }
        else if (arr[mid] < key)
            beg = mid + 1;
        else
            end = mid - 1;
    }

    return ans;
}

pair<int, int> find_extreme_occurrences(const vector<int>& arr, int key) {
    int first_occurrence = find_first_occurrence(arr, key);
    int last_occurrence = find_last_occurrence(arr, key);

    return {first_occurrence, last_occurrence};
}

int main() {
    vector<int> arr = {0, 0, 1, 1, 1, 2, 5};
    int key = 1;

    pair<int, int> occurrences = find_extreme_occurrences(arr, key);
    cout << occurrences.first << " " << occurrences.second;

    return 0;
}