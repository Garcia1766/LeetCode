#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<int> res(n, 1);
        for (int j = 0; j < n; j++) {
            if (obstacleGrid[0][j] == 1) {
                for (int j1 = j; j1 < n; j1++) {
                    res[j1] = 0;
                }
                break;
            }
        }
        for (int i = 1; i < m; i++) {
            if (obstacleGrid[i][0] == 1) res[0] = 0;
            for (int j = 1; j < n; j++) {
                if (obstacleGrid[i][j] == 1) {
                    res[j] = 0;
                } else {
                    res[j] = res[j - 1] + res[j];
                }
            }
        }
        return res[n - 1];
    }
};
