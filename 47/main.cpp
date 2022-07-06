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
    unordered_map<int, int> counter;
    void generatePermutation(const vector<int>& nums, int idx, vector<int> stored){
        if (idx == nums.size()) {
            res.push_back(stored);
            return;
        }
        for (auto it : counter) {
            if (it.second > 0) {
                stored.push_back(it.first);
                counter[it.first]--;
                generatePermutation(nums, idx + 1, stored);
                stored.pop_back();
                counter[it.first]++;
            }
        }
        return;
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        for (int i : nums) {
            if (counter.find(i) == counter.end()) counter[i] = 1;
            else counter[i] += 1;
        }
        generatePermutation(nums, 0, vector<int>());
        return res;
    }
};

int main() {
    string digits = "abab";
    vector<int> nums = {1,1,2};
    vector<vector<int>> res = Solution().permuteUnique(nums);
    for (int i = 0; i < res.size(); i++) {
        print_vector(res[i], false);
        printf(", ");
    } printf("\n");
    return 0;
}