#include <iostream>
#include <vector>
using namespace std;

int find_pivot_index(const vector<int>& arr) {
    int beg = 0, end = arr.size() - 1;

    while (beg < end) {
        int mid = beg + (end - beg) / 2;

        if (arr[mid] >= arr[0])
            beg = mid + 1;
        else
            end = mid;
    }

    return beg;
}

int find(const vector<int>& arr, int beg, int end, int key) {
    while (beg <= end) {
        int mid = beg + (end - beg) / 2;

        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            beg = mid + 1;
        else
            end = mid - 1;
    }

    return -1;
}

int search(const vector<int>& arr, int key) {
    int pivot_index = find_pivot_index(arr);

    if (key >= arr[0])
        return find(arr, 0, pivot_index - 1, key);
    else
        return find(arr, pivot_index, arr.size() - 1, key);
}

int main() {
    vector<int> arr = {7, 9, 1, 2, 3, 4};
    int key = 2;

    int index = search(arr, key);
    cout << index;

    return 0;
}