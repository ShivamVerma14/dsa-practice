#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> find_pairs_with_sum(vector<int>& nums, int sum) {
    vector<vector<int>> pairs;

    sort(nums.begin(), nums.end());

    for (int i = 0; i < nums.size(); i++)
        for (int j = i + 1; j < nums.size(); j++)
            if (nums[i] + nums[j] == sum)
                pairs.push_back({nums[i], nums[j]});
    
    return pairs;
}

int main() {
    vector<int> nums = {2, -3, 3, 3, -2};
    int s = 0;

    vector<vector<int>> pairs = find_pairs_with_sum(nums, s);
    
    for (auto& pair : pairs) {
        for (int& num : pair)
            cout << num << " ";
        cout << endl;
    }

    return 0;
}