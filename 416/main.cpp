#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for (auto v : nums) {
            sum += v;
        }
        if (sum % 2) {
            return false;
        }

        int target = sum / 2;
        vector<vector<bool>> dp(n, vector<bool>(target + 1, false));
        for (int i = 0; i < n; ++i) {
            dp[i][0] = true;
        }
        for (int i = 1; i < n; ++i) {
            for (int j = 1; j < target + 1; ++j) {
                if (j >= nums[i]) {
                    dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i]];
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[n - 1][target];
    }
};

int main() {
    vector<int> nums = {1,2,3,5};
    bool res = Solution().canPartition(nums);
    printf("%d\n", res);
    return 0;
}