#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> find_prev_smaller_elements(const vector<int>& arr) {
    vector<int> ans(arr.size());

    stack<int> s;
    s.push(-1);

    for (int i = 0; i < arr.size(); i++) {
        int element = arr[i];

        while (!s.empty() && s.top() >= element)
            s.pop();

        ans[i] = s.top();
        s.push(element);
    }

    return ans;
}

int main() {
    vector<int> arr = {2, 4, 1, 3};
    
    vector<int> prev_smaller_elements = find_prev_smaller_elements(arr);
    for (int& num : prev_smaller_elements)
        cout << num << " ";

    return 0;
}