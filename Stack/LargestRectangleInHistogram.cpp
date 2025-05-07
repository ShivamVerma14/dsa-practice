/*
Given an array of integers 'heights' representing the histogram's bar height where the width
of each bar is 1, return the area of the largest rectangle in the histogram.
*/

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> find_next_smaller_index(vector<int>& arr) {
    stack<int> s;
    s.push(-1);

    vector<int> ans(arr.size());

    for (int i = arr.size() - 1; i >= 0; i--) {
        int element = arr[i];

        while (s.top() != -1 && arr[s.top()] >= element)
            s.pop();

        ans[i] = s.top();
        s.push(i);
    }

    return ans;
}

vector<int> find_prev_smaller_index(vector<int>& arr) {
    stack<int> s;
    s.push(-1);

    vector<int> ans(arr.size());

    for (int i = 0; i < arr.size(); i++) {
        int element = arr[i];

        while (s.top() != -1 && arr[s.top()] >= element)
            s.pop();

        ans[i] = s.top();
        s.push(i);
    }

    return ans;
}

int find_largest_rectangle_area(vector<int>& heights) {
    vector<int> next_smaller = find_next_smaller_index(heights);
    vector<int> prev_smaller = find_prev_smaller_index(heights);

    int max_area = 0;
    for (int i = 0; i < heights.size(); i++) {
        int height = heights[i];

        if (next_smaller[i] == -1)
            next_smaller[i] = heights.size();
        
        int width = next_smaller[i] - prev_smaller[i] - 1;

        max_area = max(max_area, width * height);
    }

    return max_area;
}

int main() {
    vector<int> heights = {2, 1, 5, 6, 2, 3};

    int area = find_largest_rectangle_area(heights);
    cout << area;

    return 0;
}

/* Time complexity: O(n^2)

int find_largest_rectangle_area(vector<int>& heights) {
    int max_area = 0;

    for (int i = 0; i < heights.size(); i++) {
        int width = 1;
        int height = heights[i];

        int left = i - 1;
        while (left >= 0 && heights[left] >= height) {
            width++;
            left--;
        }

        int right = i + 1;
        while (right < heights.size() && heights[right] >= height) {
            width++;
            right++;
        }

        max_area = max(max_area, width * height);
    }

    return max_area;
}
*/