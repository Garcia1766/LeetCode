#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n <= 1) return 0;

        vector<int> leftProfit(n, 0);
        vector<int> rightProfit(n + 1, 0);
        int leftMin = prices[0];
        int rightMax = prices[n - 1];

        for (int i = 1; i < n; ++i) {
            leftProfit[i] = max(leftProfit[i - 1], prices[i] - leftMin);
            leftMin = min(leftMin, prices[i]);

            int j = n - i - 1;
            rightProfit[j] = max(rightProfit[j + 1], rightMax - prices[j]);
            rightMax = max(rightMax, prices[j]);
        }
        int res = 0;
        for (int i = 0; i < n; ++i) {
            res = max(res, leftProfit[i] + rightProfit[i + 1]);
        }
        return res;
    }
};

int main() {
    vector<int> prices = {3,3,5,0,0,3,1,4};
    int res = Solution().maxProfit(prices);
    printf("%d\n", res);
    return 0;
}
