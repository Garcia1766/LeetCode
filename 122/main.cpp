#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int reset = 0;
        int held = INT32_MIN;
        int old_reset;
        for (int i = 0; i < n; i++) {
            old_reset = reset;
            reset = max(reset, held + prices[i]);
            held = max(held, old_reset - prices[i]);
        }
        return reset;
    }
};

int main() {
    vector<int> prices = {1,2,3,4,5};
    int res = Solution().maxProfit(prices);
    printf("%d\n", res);
    return 0;
}

// Can also use peak-valley approach: Ans = \Sigma (Peak_i - Valley_i)
