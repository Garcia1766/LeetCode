#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            int l = i + 1, r = nums.size() - 1;
            while (l < r) {
                int tmp = nums[i] + nums[l] + nums[r];
                if (tmp < 0)
                    l++;
                else if (tmp > 0)
                    r--;
                else {
                    int arr[3] = {nums[i], nums[l], nums[r]};
                    ans.push_back(vector<int>(arr, arr + 3));
                    l++;
                    while (nums[l] == nums[l - 1] && l < r)
                        l++;
                }
            }
        }
        return ans;
    }
};

int main() {
    int arr[] = {-1, 0, 1, 2, -1, -4};
    vector<int> nums(arr, arr + sizeof(arr) / sizeof(int));
    vector<vector<int>> ans = Solution().threeSum(nums);
    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[i].size(); j++)
            cout << ans[i][j] << " ";
        cout << endl;
    }

    return 0;
}