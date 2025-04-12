#include <iostream>
#include <vector>
using namespace std;

bool is_sorted_rotated(vector<int>& nums) {
    int count = 0;

    for (int i = 1; i < nums.size(); i++)
        if (nums[i - 1] > nums[i])
            count++;

    if (nums.back() > nums.front())
        count++;

    return count == 1;
}

int main() {
    vector<int> nums = {3, 4, 5, 1, 2};

    if (is_sorted_rotated(nums))
        cout << "Yes";
    else
        cout << "No";

    return 0;
}