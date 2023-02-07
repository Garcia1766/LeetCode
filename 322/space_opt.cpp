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

        vector<int> dp(amount + 1, 10001);
        dp[0] = 0;

        for (int i = 0; i < n; ++i) {
            for (int j = coins[i]; j < amount + 1; ++j) {
                dp[j] = min(dp[j], dp[j - coins[i]] + 1);
            }
        }

        return dp[amount] == 10001 ? -1 : dp[amount];
    }
};

int main() {
    vector<int> coins = {1,2,5};
    int amount = 11;
    int res = Solution().coinChange(coins, amount);
    printf("%d\n", res);
    return 0;
}