#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<cassert>
#include<unordered_map>
#include<algorithm>

using namespace std;

void print_vector(vector<int> vec, bool newline = true){
    printf("[");
    for (int i = 0; i < vec.size(); i++)
        printf("%d,", vec[i]);
    printf("]");
    if (newline) printf("\n");
}

void print_mat(vector<vector<char>> mat) {
    for (auto a : mat) {
        for (auto b : a) {
            printf("%c ", b);
        }
        printf("\n");
    }
}

class Solution {
private:
    int res;
    int M, N;
    vector<vector<bool>> visited;
    vector<vector<int>> delta = {{0, 1}, {-1, 0}, {0, -1}, {1, 0}};
    bool inBoard(int x, int y) {
        return 0 <= x && x < M && 0 <= y && y < N;
    }

    void dfs(const vector<vector<char>>& grid, int x, int y) {
        visited[x][y] = true;
        for (auto dt : delta) {
            int nx = x + dt[0];
            int ny = y + dt[1];
            if (inBoard(nx, ny) && !visited[nx][ny] && grid[nx][ny] == '1') {
                dfs(grid, nx, ny);
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        res = 0;
        M = grid.size();
        assert(M > 0);
        N = grid[0].size();
        visited = vector<vector<bool>>(M, vector<bool>(N, false));

        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                if (!visited[i][j] && grid[i][j] == '1') {
                    res += 1;
                    dfs(grid, i, j);
                }
            }
        }
        return res;
    }
};

int main() {
    vector<vector<char>> grid = {{'1','1','0','0','0'},{'1','1','0','0','0'},{'0','0','1','0','0'},{'0','0','0','1','1'}};
    int res = Solution().numIslands(grid);
    printf("%d\n", res);
    return 0;
}
