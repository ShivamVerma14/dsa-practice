#include <iostream>
#include <vector>
using namespace std;

int find_pivot_element(const vector<int>& arr) {
    int beg = 0, end = arr.size() - 1;

    while (beg < end) {
        int mid = beg + (end - beg) / 2;

        if (arr[mid] >= arr[0])
            beg = mid + 1;
        else    
            end = mid;
    }

    return arr[beg];
}

int main() {
    vector<int> arr = {7, 9, 1, 2, 3, 4};

    int element = find_pivot_element(arr);
    cout << element;

    return 0;
}