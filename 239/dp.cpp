#include<iostream>
#include<vector>

using namespace std;

void print_vec(vector<int>& nums) {
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");
}

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        if (k == 1) return nums;

        vector<int> left(n, INT32_MIN);
        left[0] = nums[0];
        vector<int> right(n, INT32_MIN);
        right[n - 1] = nums[n - 1];
        for (int i = 1; i < n; ++i) {
            if (i % k == 0) {
                left[i] = nums[i];
            } else {
                left[i] = max(left[i - 1], nums[i]);
            }

            int j = n - 1 - i;
            if ((j + 1) % k == 0) {
                right[j] = nums[j];
            } else {
                right[j] = max(right[j + 1], nums[j]);
            }
        }

        vector<int> res(n - k + 1, INT32_MIN);
        for (int i = 0; i < n - k + 1; ++i) {
            res[i] = max(right[i], left[i + k - 1]);
        }
        return res;
    }
};

int main() {
    vector<int> nums = {1,3,-1,-3,5,3,6,7};
    int k = 3;
    vector<int> res = Solution().maxSlidingWindow(nums, k);
    for (int i = 0 ; i < res.size(); ++i) {
        printf("%d ", res[i]);
    }
    printf("\n");
    return 0;
}
