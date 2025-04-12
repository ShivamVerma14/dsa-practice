#include <bits/stdc++.h>
using namespace std;

void right_rotate(vector<int> &arr, int k) {
    k %= arr.size();
    reverse(arr.begin(), arr.end());
    reverse(arr.begin(), arr.begin() + k);
    reverse(arr.begin() + k, arr.end());
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    int k = 3;

    right_rotate(arr, k);
    for (int &num : arr)
        cout << num << " ";

    return 0;
}