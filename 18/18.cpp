#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            
            for (int j = i + 1; j < nums.size(); j++) {
                if (j > i + 1 && nums[j] == nums[j - 1])
                    continue;
                
                int l = j + 1, r = nums.size() - 1;
                while (l < r) {
                    int tmp = nums[i] + nums[j] + nums[l] + nums[r];
                    if (tmp < target)
                        l++;
                    else if (tmp > target)
                        r--;
                    else {
                        int arr[4] = {nums[i], nums[j], nums[l], nums[r]};
                        ans.push_back(vector<int>(arr, arr + 4));
                        l++;
                        while (nums[l] == nums[l - 1] && l < r)
                            l++;
                    }
                }
            }
        }
        return ans;
    }
};

int main() {
    int arr[] = {1, 0, -1, 0, -2, 2}, target = 0;
    vector<int> nums(arr, arr + sizeof(arr) / sizeof(int));
    vector<vector<int>> ans = Solution().fourSum(nums, target);
    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[i].size(); j++)
            cout << ans[i][j] << " ";
        cout << endl;
    }

    return 0;
}