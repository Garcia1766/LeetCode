#include<iostream>
#include<vector>
#include<deque>

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
    deque<int> deq;

    void clean_deque(vector<int>& nums, int i, int k) {
        if (!deq.empty() && deq.front() <= i - k) {
            deq.pop_front();
        }
        while (!deq.empty() && nums[deq.back()] < nums[i]) {
            deq.pop_back();
        }
    }

    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        if (k == 1) return nums;

        int maxIdx = 0;
        for (int i = 0; i < k; ++i) {
            clean_deque(nums, i, k);
            deq.push_back(i);
            if (nums[i] > nums[maxIdx]) {
                maxIdx = i;
            }
        }
        vector<int> res(n - k + 1, INT32_MIN);
        res[0] = nums[maxIdx];

        for (int i = k; i < n; ++i) {
            clean_deque(nums, i, k);
            deq.push_back(i);
            res[i - k + 1] = nums[deq.front()];
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
