// O(N^2)
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n == 1) return 0;
        if (n == 2) return max(0, prices[1] - prices[0]);

        vector<int> res(n, 0);
        res[1] = max(0, prices[1] - prices[0]);
        for (int i = 2; i < n; i++) {
            res[i] = res[i - 1];
            for (int j = i - 1; j >= 2; j--) {
                res[i] = max(res[i], res[j - 2] + prices[i] - prices[j]);
            }
            res[i] = max(res[i], prices[i] - prices[1]);
            res[i] = max(res[i], prices[i] - prices[0]);
        }
        return res[n - 1];
    }
};

int main() {
    vector<int> prices = {1,2,3,0,2};
    int res = Solution().maxProfit(prices);
    printf("%d\n", res);
    return 0;
}
