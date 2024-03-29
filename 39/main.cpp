#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<cassert>
#include<unordered_map>
#include<algorithm>

using namespace std;

void print_vector(vector<int> vec, bool newline = false){
    printf("[");
    for (int i = 0; i < vec.size(); i++)
        printf("%d,", vec[i]);
    printf("]");
    if (newline) printf("\n");
}

class Solution {
private:
    vector<vector<int>> res;
    void generateCombination(const vector<int>& candidates, int target, int start, vector<int>& stored) {
        if (target == 0) {
            res.push_back(stored);
            return;
        }
        for (int i = start; i < candidates.size(); i++) {
            if (candidates[i] > target) break;
            stored.push_back(candidates[i]);
            generateCombination(candidates, target - candidates[i], i, stored);  // 第3个参数传入i而非i+1，意为允许重复使用元素
            stored.pop_back();
        }
        return;
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());  // 默认从小到大
        vector<int> stored;
        generateCombination(candidates, target, 0, stored);
        return res;
    }
};

int main() {
    vector<int> candidates = {2,3,6,7};
    int target = 7;
    vector<vector<int>> res = Solution().combinationSum(candidates, target);
    for (int i = 0; i < res.size(); i++) {
        print_vector(res[i], false);
        printf(", ");
    } printf("\n");
    return 0;
}