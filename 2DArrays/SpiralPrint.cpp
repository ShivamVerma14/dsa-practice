#include <iostream>
#include <vector>
using namespace std;

void spiral_print(vector<vector<int>>& mat) {
    int top = 0, left = 0;
    int right = mat[0].size() - 1, bottom = mat.size() - 1;
    int count = 0;
    int total_elements = mat.size() * mat[0].size();

    while (count < total_elements) {
        for (int i = left; count < total_elements && i <= right; i++) {
            cout << mat[top][i] << " ";
            count++;
        }
        top++;

        for (int i = top; count < total_elements && i <= bottom; i++) {
            cout << mat[i][right] << " ";
            count++;
        }
        right--;

        for (int i = right; count < total_elements && i >= left; i--) {
            cout << mat[bottom][i] << " ";
            count++;
        }
        bottom--;

        for (int i = bottom; count < total_elements && i >= top; i--) {
            cout << mat[i][left] << " ";
            count++;
        }
        left++;
    }
}

int main() {
    vector<vector<int>> mat = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };

    spiral_print(mat);
    return 0;
}