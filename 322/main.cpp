#include<iostream>
#include<vector>

using namespace std;

void print_mat(vector<vector<int>>& mat) {
    for (auto vec : mat) {
        for (auto v : vec) {
            printf("%d ", v);
        }
        printf("\n");
    }
    printf("\n");
}

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();

        vector<vector<int>> dp(n + 1, vector<int>(amount + 1, 10001));
        for (int i = 0; i < n + 1; ++i) {
            dp[i][0] = 0;
        }

        for (int i = 1; i < n + 1; ++i) {
            for (int j = 1; j < amount + 1; ++j) {
                // TLE
                // for (int k = 0; k * coins[i - 1] <= j; ++k) {
                //     dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - k * coins[i - 1]] + k);
                // }
                if (j - coins[i - 1] >= 0) {
                    dp[i][j] = min(dp[i - 1][j], dp[i][j - coins[i - 1]] + 1);
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        return dp[n][amount] == 10001 ? -1 : dp[n][amount];
    }
};

int main() {
    vector<int> coins = {1,2,5};
    int amount = 11;
    int res = Solution().coinChange(coins, amount);
    printf("%d\n", res);
    return 0;
}