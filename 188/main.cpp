#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if (n <= 1) return 0;

        if (2 * k + 1 >= n) {
            int res = 0;
            for (int i = 0; i < n - 1; i++) {
                if (prices[i] < prices[i + 1]) {
                    res += prices[i + 1] - prices[i];
                }
            }
            return res;
        }

        // dp[day_i][used_k][is_hold] = balance
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(k + 1, vector<int>(2, INT32_MIN + 1000)));  // avoid overflow
        dp[0][0][0] = 0;
        dp[0][1][1] = -prices[0];
        for (int i = 1; i < n; i++) {  // j == 0
            dp[i][0][0] = 0;
        }
        for (int j = 1; j <= k; j++) {
            for (int i = 1; i < n; i++) {
                dp[i][j][0] = max(dp[i - 1][j][0], dp[i - 1][j][1] + prices[i]);
                dp[i][j][1] = max(dp[i - 1][j][1], dp[i - 1][j - 1][0] - prices[i]);
            }
        }

        int res = 0;
        for (int j = 0; j <= k; j++) {
            res = max(res, dp[n - 1][j][0]);
        }
        return res;
    }
};

int main() {
    vector<int> prices = {3,2,6,5,0,3};
    int k = 2;
    int res = Solution().maxProfit(k, prices);
    printf("%d\n", res);
    return 0;
}
