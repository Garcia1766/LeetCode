#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map1;
        for (int i = 0; i<nums.size(); i++) {
            if (map1.find(target - nums[i]) != map1.end()) {  // found
                int arr[2] = {map1[target - nums[i]], i};
                return vector<int>(arr, arr + 2);
            } else {
                map1[nums[i]] = i;
            }
        }
        throw invalid_argument("the input has no solution");
    }
};

int main() {
    int arr[] = {2, 7, 11, 15}, target = 9;
    vector<int> nums(arr, arr + sizeof(arr) / sizeof(int));
    vector<int> ans = Solution().twoSum(nums, target);
    cout << ans[0] << ' ' << ans[1] << endl;

    return 0;
}