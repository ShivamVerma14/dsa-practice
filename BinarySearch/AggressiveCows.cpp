/*
Given an array of length 'n', where each element denotes the position of a stall. Now you have 'N' stalls
and an integer 'k' which denotes the number of cows that are aggressive. To prevent the cows from hurting
each other, you need to assign the cows to the stalls, such that the minimum distance between the two of
them is as large as possible. Return the largest minimum distance.
*/

#include <bits/stdc++.h>
using namespace std;

bool is_possible_solution(vector<int>& arr, int k, int mid) {
    int cows_count = 1;
    int last_position = arr[0];

    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] - last_position >= mid) {
            cows_count++;
            if (cows_count == k)
                return true;
            last_position = arr[i];
        }
    }

    return false;
}

int find_largest_distance(vector<int>& arr, int k) {
    sort(arr.begin(), arr.end());

    int beg = 0;
    int end = arr.back() - arr.front();

    int ans = -1;

    while (beg <= end) {
        int mid = beg + (end - mid) / 2;

        if (is_possible_solution(arr, k, mid)) {
            ans = mid;
            beg = mid + 1;
        }
        else
            end = mid - 1;
    }

    return ans;
}

int main() {
    vector<int> arr = {4, 2, 1, 3, 6};
    int k = 2;

    int largest_distance = find_largest_distance(arr, k);
    cout << largest_distance;
    
    return 0;
}