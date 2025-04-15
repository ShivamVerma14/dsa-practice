#include <iostream>
#include <vector>
using namespace std;

void wave_print(vector<vector<int>>& mat) {
    for (int col = 0; col < mat[0].size(); col++) {
        if (col & 1) {
            for (int row = mat.size() - 1; row >= 0; row--)
                cout << mat[row][col] << " ";
            cout << endl;
        } 
        else {
            for (int row = 0; row < mat.size(); row++)
                cout << mat[row][col] << " ";
            cout << endl;
        }       
    }
}

int main() {
    vector<vector<int>> mat = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };

    wave_print(mat);
    return 0;
}