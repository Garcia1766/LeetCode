#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<cassert>
#include<unordered_map>
#include<unordered_set>
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
    void generateCombination(const vector<int>& candidates, int n, int k, int start, vector<int>& stored) {
        if (n == 0 && k == 0) {
            res.push_back(stored);
            return;
        }
        if (n <= 0 || k == 0) {
            return;
        }

        for (int i = start; i < candidates.size(); i++) {
            if (candidates[i] <= n) {
                stored.push_back(candidates[i]);
                generateCombination(candidates, n - candidates[i], k - 1, i + 1, stored);
                stored.pop_back();
            } else {
                break;
            }
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> candidates = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        vector<int> stored;
        generateCombination(candidates, n, k, 0, stored);
        return res;
    }
};

int main() {
    int n = 1, k = 4;
    vector<vector<int>> res = Solution().combinationSum3(k, n);
    for (int i = 0; i < res.size(); i++) {
        print_vector(res[i], false);
        printf(", ");
    } printf("\n");
    return 0;
}