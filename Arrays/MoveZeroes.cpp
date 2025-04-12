#include <iostream>
#include <vector>
using namespace std;

void move_zeroes(vector<int>& nums) {
    int j = 0;
    
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] != 0) {
            nums[j] = nums[i];
            j++;
        }
    }

    while (j < nums.size()) {
        nums[j] = 0;
        j++;
    }
}

int main() {
    vector<int> nums = {1, 0, 3, 5, 0, 4};
    move_zeroes(nums);

    for (int& num : nums)
        cout << num << " ";

    return 0;
}