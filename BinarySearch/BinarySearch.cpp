#include <iostream>
#include <vector>
using namespace std;

int search(const vector<int>& arr, int key) {
    int beg = 0, end = arr.size() - 1;
    
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

int main() {
    vector<int> arr = {2, 4, 6, 8, 12, 16};
    int key = 12;

    int index = search(arr, key);
    cout << index;

    return 0;
}