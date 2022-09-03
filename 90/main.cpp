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
        // How many tar-th elements do we take? - rep
        int rep = 1;
        for (int i = tar; i < nums.size(); i++) {
            if (i < nums.size() - 1 && nums[i + 1] == nums[i]) {
                rep++;
            } else {
                break;
            }
        }
        /**
        for (int i = 0; i <= rep; i++) {
            for (int j = 0; j < i; j++) {
                stored.push_back(nums[tar]);
            }
            generateSubset(nums, tar + rep, stored);
            for (int j = 0; j < i; j++) {
                stored.pop_back();
            }
        }
        */
       // accelerated compared to above
        for (int i = 0; i <= rep; i++) {
            if (i > 0) {
                stored.push_back(nums[tar]);
            }
            generateSubset(nums, tar + rep, stored);
            if (i == rep) {
                for (int j = 0; j < i; j++) {
                    stored.pop_back();
                }
            }
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> stored;
        generateSubset(nums, 0, stored);
        return res;
    }
};

int main() {
    vector<int> nums = {1,2,2};
    vector<vector<int>> res = Solution().subsetsWithDup(nums);
    for (int i = 0; i < res.size(); i++) {
        print_vector(res[i], false);
        printf(", ");
    } printf("\n");
    return 0;
}
