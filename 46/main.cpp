#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<cassert>

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
    vector<bool> used;
    void generatePermutation(const vector<int>& nums, int idx, vector<int> stored){
        if (idx == nums.size()) {
            res.push_back(stored);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (!used[i]) {
                stored.push_back(nums[i]);
                used[i] = true;
                generatePermutation(nums, idx + 1, stored);
                stored.pop_back();
                used[i] = false;
            }
        }
        return;
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        used = vector<bool>(nums.size(), false);
        generatePermutation(nums, 0, vector<int>());
        return res;
    }
};

int main() {
    string digits = "abab";
    vector<int> nums = {1,2,3};
    vector<vector<int>> res = Solution().permute(nums);
    for (int i = 0; i < res.size(); i++) {
        print_vector(res[i], false);
        printf(", ");
    } printf("\n");
    return 0;
}