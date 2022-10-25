/* O(n) memory */
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> res(n, 0);
        res[0] = grid[0][0];
        for (int j = 1; j < n; j++) {
            res[j] = res[j - 1] + grid[0][j];
        }

        for (int i = 1; i < m; i++) {
            res[0] += grid[i][0];
            for (int j = 1; j < n; j++) {
                res[j] = min(res[j - 1], res[j]) + grid[i][j];
            }
        }
        return res[n - 1];
    }
};

int main() {
    vector<vector<int>> grid = {{1,3,1},{1,5,1},{4,2,1}};
    int res = Solution().minPathSum(grid);
    printf("%d\n", res);

    return 0;
}
