#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<cassert>
#include<unordered_map>
#include<algorithm>

using namespace std;

void print_vector(vector<int> vec, bool newline = true){
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
        // for循环每次更新i不是加1，而是跳至下一个值的第一个位置
        for (int i = start; i < candidates.size();) {
            if (candidates[i] > target) break;

            stored.push_back(candidates[i]);
            generateCombination(candidates, target - candidates[i], i + 1, stored);
            stored.pop_back();

            while (i < candidates.size() - 1 && candidates[i + 1] == candidates[i])
                i++;
            i++;
        }
        return;
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());  // 默认从小到大
        vector<int> stored;
        generateCombination(candidates, target, 0, stored);
        return res;
    }
};

int main() {
    vector<int> candidates = {10,1,2,7,6,1,5};
    int target = 8;
    vector<vector<int>> res = Solution().combinationSum2(candidates, target);
    for (int i = 0; i < res.size(); i++) {
        print_vector(res[i], false);
        printf(", ");
    } printf("\n");
    return 0;
}