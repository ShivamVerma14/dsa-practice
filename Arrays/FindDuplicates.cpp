#include <bits/stdc++.h>
using namespace std;

int find_duplicate(vector<int>& arr) {
    int n = arr.size();

    int sum_of_arr = accumulate(arr.begin(), arr.end(), 0);
    int sum_till_n = (n - 1) * n / 2;

    return sum_of_arr - sum_till_n;
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 3};

    int duplicate = find_duplicate(arr);
    cout << duplicate;

    return 0;
}