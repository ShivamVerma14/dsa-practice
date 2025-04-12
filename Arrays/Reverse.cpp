#include <iostream>
#include <vector>
using namespace std;

void reverse(vector<int>& nums) {
    int i = 0, j = nums.size() - 1;

    while (i < j) {
        swap(nums[i], nums[j]);
        i++;
        j--;
    }
}

int main() {
    vector<int> nums = {1, 2, 3, 4, 5};
    reverse(nums);

    for (int& num : nums)
        cout << num << " ";

    return 0;
}