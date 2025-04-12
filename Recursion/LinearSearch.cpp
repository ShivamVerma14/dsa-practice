#include <iostream>
#include <vector>
using namespace std;

bool find(const vector<int>& arr, int index, int key) {
    if (index == arr.size())
        return false;

    if (arr[index] == key)
        return true;

    return find(arr, index + 1, key);
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    int key = 4;

    if (find(arr, 0, key))
        cout << "Yes";
    else
        cout << "No";

    return 0;
}