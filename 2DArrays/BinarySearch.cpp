#include <iostream>
#include <vector>
using namespace std;

bool search(vector<vector<int>>& mat, int key) {
    int m = mat.size();
    int n = mat[0].size();

    int beg = 0, end = m * n - 1;

    while (beg <= end) {
        int mid = beg + (end - beg) / 2;
        
        int row = mid / n;
        int col = mid % n;

        if (mat[row][col] == key)
            return true;
        else if (mat[row][col] < key)
            beg = mid + 1;
        else
            end = mid - 1;
    }

    return false;
}

int main() {
    vector<vector<int>> mat = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 60}
    };

    int key = 30;

    if (search(mat, key))
        cout << "Yes";
    else
        cout << "No";

    return 0;
}