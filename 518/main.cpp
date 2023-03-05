#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        sort(coins.begin(), coins.end());
        int n = coins.size();
        vector<vector<int>> dp(n + 1, vector<int>(amount + 1, 0));
        for (int i = 0; i < n + 1; ++i) {
            dp[i][0] = 1;
        }

        for (int i = 1; i < n + 1; ++i) {
            for (int j = 1; j < min(coins[i - 1], amount + 1); ++j) {
                dp[i][j] = dp[i - 1][j];
            }
            for (int j = coins[i - 1]; j < amount + 1; ++j) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - coins[i - 1]];
            }
        }

        return dp[n][amount];
    }
};

int main() {
    vector<int> coins = {1,2,5};
    int amount = 5;
    int res = Solution().change(amount, coins);
    printf("%d\n", res);
    return 0;
}
