#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void rotate(vector<vector<int>>& mat) {
    for (int i = 0; i < mat.size(); i++)
        for (int j = 0; j < i; j++)
            swap(mat[i][j], mat[j][i]);

    for (auto& row : mat)
        reverse(row.begin(), row.end());
}

int main() {
    vector<vector<int>> mat = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    rotate(mat);

    for (auto& row : mat) {
        for (int& num : row)
            cout << num << " ";
        cout << endl;
    }

    return 0;
}