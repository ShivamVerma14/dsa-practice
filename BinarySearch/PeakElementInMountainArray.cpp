#include <iostream>
#include <vector>
using namespace std;

int find_peak_element(const vector<int>& arr) {
    int beg = 0, end = arr.size() - 1;

    while (beg < end) {
        int mid = beg + (end - beg) / 2;

        if (arr[mid] < arr[mid + 1])
            beg = mid + 1;
        else
            end = mid;
    }

    return arr[beg];
}

int main() {
    vector<int> arr = {3, 4, 5, 1};
    
    int element = find_peak_element(arr);
    cout << element;

    return 0;
}