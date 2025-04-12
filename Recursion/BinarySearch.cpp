#include <iostream>
#include <vector>
using namespace std;

bool find(const vector<int>& arr, int beg, int end, int key) {
    if (beg > end)
        return false;

    int mid = beg + (end - beg) / 2;
    if (arr[mid] == key)
        return true;
    else if (arr[mid] < key)
        return find(arr, mid + 1, end, key);
    else
        return find(arr, beg, mid - 1, key);
}

int main() {
    vector<int> arr = {2, 4, 6, 10, 14, 16};
    int key = 14;

    if (find(arr, 0, arr.size() - 1, key))
        cout << "Yes";
    else
        cout << "No";

    return 0;
}