#include <iostream>
#include <vector>
using namespace std;

vector<int> find_intersection(vector<int>& a, vector<int>& b) {
    vector<int> ans;

    int i = 0, j = 0;
    while (i < a.size() && j < b.size()) {
        if (a[i] < b[j])
            i++;
        else if (a[i] > b[j])
            j++;
        else {
            ans.push_back(a[i]);
            i++;
            j++;
        }
    }

    return ans;
}

int main() {
    vector<int> a = {1, 2, 2, 2, 3, 4};
    vector<int> b = {2, 2, 3, 3};

    vector<int> intersection = find_intersection(a, b);
    for (int& num : intersection)
        cout << num << " ";

    return 0;
}