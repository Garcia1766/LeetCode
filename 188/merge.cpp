#include<iostream>
#include<vector>

using namespace std;

void print_trans(vector<pair<int, int>>& trans) {
    for (int i = 0; i < trans.size(); ++i) {
        printf("[%d,%d], ", trans[i].first, trans[i].second);
    }
    printf("\n");
}

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if (n <= 1) return 0;

        vector<pair<int, int>> trans;
        int start = 0;
        int end = 0;
        for (int i = 0; i < n - 1; ++i) {
            if (prices[i + 1] > prices[i]) {
                end = i + 1;
            } else {
                if (end > start) {
                    trans.push_back(make_pair(start, end));
                }
                start = i + 1;
            }
        }
        if (end > start) {
            trans.push_back(make_pair(start, end));
        }

        while(trans.size() > k) {
            // check delete loss
            int del_loss = INT32_MAX;
            vector<pair<int, int>>::iterator del_idx;
            for (auto iter = trans.begin(); iter != trans.end(); ++iter) {
                if (prices[iter->second] - prices[iter->first] < del_loss) {
                    del_loss = prices[iter->second] - prices[iter->first];
                    del_idx = iter;
                }
            }

            // check merge loss
            int merge_loss = INT32_MAX;
            vector<pair<int, int>>::iterator merge_idx;
            for (auto iter = trans.begin(); iter != trans.end() - 1; ++iter) {
                if (prices[iter->second] - prices[(iter + 1)->first] < merge_loss) {
                    merge_loss = prices[iter->second] - prices[(iter + 1)->first];
                    merge_idx = iter;
                }
            }

            // delete or merge
            if (del_loss < merge_loss) {
                trans.erase(del_idx);
            } else {
                merge_idx->second = (merge_idx + 1)->second;
                trans.erase(merge_idx + 1);
            }
        }

        int res = 0;
        for (auto tran : trans) {
            res += prices[tran.second] - prices[tran.first];
        }
        return res;
    }
};

int main() {
    vector<int> prices = {3,2,6,5,0,3};
    int k = 2;
    int res = Solution().maxProfit(k, prices);
    printf("%d\n", res);
    return 0;
}
