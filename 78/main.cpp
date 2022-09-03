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
    void generateSubset(const vector<int>& nums, int tar, vector<int>& stored) {
        if (tar >= nums.size()) {
            res.push_back(stored);
            return;
        }

        // not taking the tar-th num
        generateSubset(nums, tar + 1, stored);

        // taking the tar-th num
        stored.push_back(nums[tar]);
        generateSubset(nums, tar + 1, stored);
        stored.pop_back();
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> stored;
        generateSubset(nums, 0, stored);
        return res;
    }
};

int main() {
    vector<int> candidates = {1,2,3};
    int target = 8;
    vector<vector<int>> res = Solution().subsets(candidates);
    for (int i = 0; i < res.size(); i++) {
        print_vector(res[i], false);
        printf(", ");
    } printf("\n");
    return 0;
}
