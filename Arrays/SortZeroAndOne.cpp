#include <iostream>
#include <vector>
using namespace std;

void sort(vector<int>& nums) {
    int i = 0, j = nums.size() - 1;

    while (i < j) {
        while (i < j && nums[i] == 0)
            i++;

        while (i < j && nums[j] == 1)
            j--;

        swap(nums[i], nums[j]);
    }
}

int main() {
    vector<int> nums = {1, 0, 0, 1, 1, 0, 0};

    sort(nums);
    for (int& num : nums)
        cout << num << " ";

    return 0;
}