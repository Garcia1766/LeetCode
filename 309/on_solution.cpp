// O(N)
#include<iostream>
#include<vector>

using namespace std;

// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/solutions/601810/best-time-to-buy-and-sell-stock-with-cooldown/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> reset(n + 1, 0);
        vector<int> held(n + 1, INT32_MIN);
        vector<int> sold(n + 1, INT32_MIN);
        for (int i = 0; i < n; i++) {
            reset[i + 1] = max(sold[i], reset[i]);
            held[i + 1] = max(held[i], reset[i] - prices[i]);
            sold[i + 1] = held[i] + prices[i];
        }
        return max(reset[n], sold[n]);
    }
};

int main() {
    vector<int> prices = {1,2,3,0,2};
    int res = Solution().maxProfit(prices);
    printf("%d\n", res);
    return 0;
}
