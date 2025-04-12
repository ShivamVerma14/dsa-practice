#include <iostream>
#include <vector>
using namespace std;

vector<int> merge(const vector<int>& a, const vector<int>& b) {
    vector<int> ans;

    int i = 0, j = 0;
    while (i < a.size() && j < b.size()) {
        if (a[i] <= b[j]) {
            ans.push_back(a[i]);
            i++;
        } else {
            ans.push_back(b[j]);
            j++;
        }
    }

    while (i < a.size()) {
        ans.push_back(a[i]);
        i++;
    }

    while (j < b.size()) {
        ans.push_back(b[j]);
        j++;
    }

    return ans;
}

int main() {
    vector<int> a = {1, 2, 3};
    vector<int> b = {2, 5, 6};

    vector<int> merged_array = merge(a, b);
    for (int& num : merged_array)
        cout << num << " ";

    return 0;
}