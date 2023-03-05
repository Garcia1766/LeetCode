#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        sort(coins.begin(), coins.end());
        int n = coins.size();
        vector<int> dp(amount + 1, 0);
        dp[0] = 1;

        for (int i = 1; i < n + 1; ++i) {
            for (int j = coins[i - 1]; j < amount + 1; ++j) {
                dp[j] = dp[j] + dp[j - coins[i - 1]];
            }
        }

        return dp[amount];
    }
};

int main() {
    vector<int> coins = {1,2,5};
    int amount = 5;
    int res = Solution().change(amount, coins);
    printf("%d\n", res);
    return 0;
}
