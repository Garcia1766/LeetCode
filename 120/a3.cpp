/*Upside down. O(n) memory*/

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
        vector<int> res(n);
        for (int j = 0; j < n; j++) {
            res[j] = triangle[n-1][j];
        }
        for (int i = n - 2; i >= 0; i--) {
            for (int j = 0; j <= i; j++) {
                res[j] = min(res[j], res[j+1]) + triangle[i][j];
            }
        }
        return res[0];
    }
};

int main() {
    vector<vector<int>> triangle = {{2},{3,4},{6,5,7},{4,1,8,3}};
    int res = Solution().minimumTotal(triangle);
    printf("%d\n", res);
    return 0;
}
