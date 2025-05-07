/*
You are given an array 'arr' of integers of length 'n'. Your task is to find the 
next smaller element for each of the array elements. Next smaller element for an 
array element is the first element to the right of that element which has a value 
strictly smaller than that element.
If for any array element the next smaller element does not exist, you should print 
-1 for that array element.
*/

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> find_next_smaller_elements(const vector<int>& arr) {
    vector<int> ans(arr.size());
    
    stack<int> s;
    s.push(-1);

    for (int i = arr.size() - 1; i >= 0; i--) {
        int element = arr[i];

        while (!s.empty() && s.top() >= element)
            s.pop();

        ans[i] = s.top();
        s.push(element);
    }

    return ans;
}

int main() {
    vector<int> arr = {2, 1, 4, 3};
    
    vector<int> next_smaller_elements = find_next_smaller_elements(arr);
    for (int& num : next_smaller_elements)
        cout << num << " ";

    return 0;
}