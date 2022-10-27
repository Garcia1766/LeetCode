#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);
        
        // res[0] include nums[0], res[1] exclude nums[0]
        vector<vector<int>> res(2, vector<int>(n, 0));
        res[0][0] = nums[0];
        res[0][1] = nums[0];
        res[1][0] = 0;
        res[1][1] = nums[1];
        for (int i = 2; i < n; i++) {
            res[0][i] = max(res[0][i - 1], res[0][i - 2] + nums[i]);
            res[1][i] = max(res[1][i - 1], res[1][i - 2] + nums[i]);
        }
        return max(res[0][n - 2], res[1][n - 1]);
    }
};
