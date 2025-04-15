/*
Write an efficient algo that searches a target value in an mxn matrix. The matrix has the following properties:
1. Integers in each row are sorted in ascending from left to right.
2. Integers in each column are sorted in ascending from top to bottom.
*/

#include <iostream>
#include <vector>
using namespace std;

bool search(vector<vector<int>>& mat, int target) {
    int m = mat.size();
    int n = mat[0].size();

    int row = 0, col = n - 1;

    while (row < m && col >= 0) {
        if (mat[row][col] == target)
            return true;
        else if (mat[row][col] < target)
            row++;
        else
            col--;
    }

    return false;
}

int main() {
    vector<vector<int>> mat = {
        {1, 4, 7, 11, 15},
        {2, 5, 8, 12, 19},
        {3, 6, 9, 16, 22},
        {10, 13, 14, 17, 24},
        {18, 21, 23, 26, 30}
    };

    int target = 5;

    if (search(mat, target))
        cout << "Yes";
    else
        cout << "No";

    return 0;
}