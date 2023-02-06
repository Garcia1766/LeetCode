#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<int> reset(n, INT32_MIN);
        vector<int> hold(n, INT32_MIN);
        reset[0] = 0;
        hold[0] = -prices[0];
        for (int i = 1; i < n; ++i) {
            reset[i] = max(reset[i - 1], hold[i - 1] + prices[i] - fee);
            hold[i] = max(hold[i - 1], reset[i - 1] - prices[i]);
        }
        return reset[n - 1];
    }
};

int main() {
    vector<int> prices = {1,3,2,8,4,9};
    int fee = 2;
    int res = Solution().maxProfit(prices, 2);
    printf("%d\n", res);
    return 0;
}
