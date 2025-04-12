#include <iostream>
#include <vector>
using namespace std;

void solve(vector<vector<int>>& mat, int n, int x, int y, string& path, vector<string>& paths, vector<vector<int>>& visited, vector<pair<pair<int, int>, char>>& move) {
    if (x < 0 || x >= n || y < 0 || y >= n || mat[x][y] == 0 || visited[x][y] == 1)
        return;

    if (x == n - 1 && y == n - 1) {
        paths.push_back(path);
        return;
    }

    visited[x][y] = 1;

    for (auto& move_pair : move) {
        int dx = move_pair.first.first;
        int dy = move_pair.first.second;
        char move_char = move_pair.second;

        path.push_back(move_char);
        solve(mat, n, x + dx, y + dy, path, paths, visited, move);
        path.pop_back();
    }

    visited[x][y] = 0;
}

vector<string> find_paths(vector<vector<int>>& mat) {
    vector<string> paths;
    int n = mat.size();

    vector<vector<int>> visited(n, vector<int>(n, 0));
    vector<pair<pair<int, int>, char>> move = {
        {{1, 0}, 'D'},
        {{0, 1}, 'R'},
        {{-1, 0}, 'L'},
        {{0, -1}, 'U'}
    };
    string path = "";

    solve(mat, n, 0, 0, path, paths, visited, move);
    return paths;
}

int main() {
    vector<vector<int>> mat = {
        {1, 0, 0, 0},
        {1, 1, 0, 0},
        {1, 1, 0, 0},
        {0, 1, 1, 1}
    };

    vector<string> paths = find_paths(mat);
    for (string& path : paths)
        cout << path << endl;

    return 0;
}