#include <iostream>
#include <vector>
using namespace std;

void solve(vector<int>& arr, int index, vector<int> subset, vector<vector<int>>& powerset) {
    if (index == arr.size()) {
        powerset.push_back(subset);
        return;
    }

    solve(arr, index + 1, subset, powerset);
    subset.push_back(arr[index]);
    solve(arr, index + 1, subset, powerset);
}

vector<vector<int>> find_powerset(vector<int>& arr) {
    vector<vector<int>> powerset;
    vector<int> subset;
    solve(arr, 0, subset, powerset);
    return powerset;
}

int main() {
    vector<int> arr = {1, 2, 3};
    vector<vector<int>> powerset = find_powerset(arr);

    for (vector<int>& subset : powerset) {
        cout << "[";
        for (int& num : subset)
            cout << num << " ";
        cout << "]" << endl;
    }

    return 0;
}