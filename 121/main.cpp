#include<iostream>
#include<vector>

using namespace std;

// Maintain min_price[] and max_profit[]
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int min_price = INT32_MAX;
        int max_profit = 0;
        for (int i = 0; i < n; i++) {
            if (prices[i] < min_price) {
                min_price = prices[i];
            } else if (prices[i] - min_price > max_profit) {
                max_profit = prices[i] - min_price;
            }
        }
        return max_profit;
    }
};

int main() {
    vector<int> prices = {7,1,5,3,6,4};
    int res = Solution().maxProfit(prices);
    printf("%d\n", res);
    return 0;
}
