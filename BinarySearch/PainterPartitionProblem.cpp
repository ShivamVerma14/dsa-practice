/*
Given an array of length 'n', where the array represents the boards and each element of the array represents 
the length of each board. Some 'k' numbers of painters are available to paint these boards. Consider that 
each unit of a board takes 1 unit of time.
You are supposed to return the area of the minimum time to get this job done of painting all the 'n' boards 
under a constraint that any painter will only paint the continuous sections of boards.
*/

#include <bits/stdc++.h>
using namespace std;

bool is_possible_solution(vector<int>& arr, int k, int mid) {
    int painter_count = 1;
    int units_painted = 0;

    for (int i = 0; i < arr.size(); i++) {
        if (units_painted + arr[i] <= mid)
            units_painted += arr[i];
        else {
            painter_count += 1;
            if (painter_count > k || arr[i] > mid)
                return false;
            units_painted = arr[i];
        }
    }

    return true;
}

int partition_time(vector<int>& arr, int k) {
    int beg = *max_element(arr.begin(), arr.end());
    int end = accumulate(arr.begin(), arr.end(), 0);

    int ans = -1;

    while (beg <= end) {
        int mid = beg + (end - mid) / 2;
        
        if (is_possible_solution(arr, k, mid)) {
            ans = mid;
            end = mid - 1;
        }
        else
            beg = mid + 1;
    }

    return ans;
}

int main() {
    vector<int> arr = {10, 20, 30, 40};
    int k = 2;

    int min_time = partition_time(arr, k);
    cout << min_time;

    return 0;
}