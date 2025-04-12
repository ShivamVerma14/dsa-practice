/*
Given an integer array 'nums' of length 'n', where all the integers of 'nums' are in the range [1, n], and each integer
appears once or twice. Return an array of all the integers that appears twice.
You must write an algorithm that runs in O(n) time and uses only constant extra space.
*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> find_all_duplicates(vector<int>& nums) {
    vector<int> duplicates;

    for (int i = 0; i < nums.size(); i++) {
        if (nums[abs(nums[i]) - 1] < 0)
            duplicates.push_back(abs(nums[i]));
        nums[abs(nums[i]) - 1] *= -1;
    }

    return duplicates;
}

int main() {
    vector<int> nums = {4, 3, 2, 7, 8, 2, 3, 1};

    vector<int> duplicates = find_all_duplicates(nums);
    for (int& num : duplicates)
        cout << num << " ";

    return 0;
}