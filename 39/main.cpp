#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<cassert>
#include<unordered_map>

using namespace std;

void print_vector(vector<int> vec, bool newline){
    printf("[");
    for (int i = 0; i < vec.size(); i++)
        printf("%d,", vec[i]);
    printf("]");
    if (newline) printf("\n");
}

class Solution {
private:
    vector<vector<int>> res;
    void generateCombination(int n, int k, int start, vector<int>& stored) {  // 此处stored传入&会大大提高运行速度
        if (stored.size() == k) {
            res.push_back(stored);
            return;
        }
        // 此时还能尝试[start, n]中的数，而离补齐k个数还差 k-stored.size() 个数，因此start最大不能超过 n-(k-stored.size())+1
        for (int i = start; i <= n - (k - stored.size()) + 1; i++) {
            stored.push_back(i);
            generateCombination(n, k, i + 1, stored);
            stored.pop_back();
        }
        return;
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> stored;
        generateCombination(n, k, 1, stored);
        return res;
    }
};

int main() {
    string digits = "abab";
    vector<int> nums = {1,1,2};
    vector<vector<int>> res = Solution().combine(4, 2);
    for (int i = 0; i < res.size(); i++) {
        print_vector(res[i], false);
        printf(", ");
    } printf("\n");
    return 0;
}