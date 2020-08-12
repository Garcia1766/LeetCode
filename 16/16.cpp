#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        
        int current_sum = nums[0] + nums[1] + nums[nums.size() - 1];

        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            int l = i + 1, r = nums.size() - 1;
            while (l < r) {
                int tmp = nums[i] + nums[l] + nums[r];
                if (abs(tmp - target) < abs(current_sum - target))
                    current_sum = tmp;

                if (tmp < target)
                    l++;
                else if (tmp > target)
                    r--;
                else {
                    return target;
                }
            }
        }
        return current_sum;
    }
};

int main() {
    int arr[] = {-1,2,1,-4}, target = 1;
    vector<int> nums(arr, arr + sizeof(arr) / sizeof(int));
    int ans = Solution().threeSumClosest(nums, target);
    cout << ans << endl;

    return 0;
}