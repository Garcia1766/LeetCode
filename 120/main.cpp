#include<iostream>
#include<vector>

using namespace std;

void print_mat(vector<vector<int>>& mat) {
    for (auto vec : mat) {
        for (int i : vec) {
            printf("%d ", i);
        }
        printf("\n");
    }
    printf("\n");
}

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> res(n, vector<int>());
        for (int i = 0; i < n; i++) {
            res[i] = vector<int>(i + 1);
        }
        res[0][0] = triangle[0][0];
        for (int i = 1; i < n; i++) {
            int m = i + 1;
            res[i][0] = res[i - 1][0] + triangle[i][0];
            for (int j = 1; j < m - 1; j++) {
                res[i][j] = min(res[i - 1][j - 1], res[i - 1][j]) + triangle[i][j];
            }
            res[i][m - 1] = res[i - 1][m - 2] + triangle[i][m - 1];
        }
        int ret = res[n - 1][0];
        for (int j = 1; j < n; j++) {
            ret = min(ret, res[n - 1][j]);
        }
        return ret;
    }
};

int main() {
    vector<vector<int>> triangle = {{2},{3,4},{6,5,7},{4,1,8,3}};
    int res = Solution().minimumTotal(triangle);
    printf("%d\n", res);
    return 0;
}
