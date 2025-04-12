#include <iostream>
#include <vector>
using namespace std;

void sort(vector<int>& nums) {
    int beg, mid, end;
    beg = mid = 0;
    end = nums.size() - 1;

    while (mid <= end) {
        if (nums[mid] == 2) {
            swap(nums[mid], nums[end]);
            end--;
        }
        else if (nums[mid] == 0) {
            swap(nums[beg], nums[mid]);
            beg++;
            mid++;
        }
        else
            mid++;
    }
}

int main() {
    vector<int> nums = {1, 0, 2, 2, 0, 0, 1, 1};
    sort(nums);

    for (int& num : nums)
        cout << num << " ";

    return 0;
}