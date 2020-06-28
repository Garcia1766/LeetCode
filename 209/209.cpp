#include<iostream>
#include<cmath>
#include<cassert>
#include<ctime>
#include<algorithm>
#include<vector>

using namespace std;

/*
左边界是纵轴，右边界是横轴，则只能向右、向下移动。一个不满足条件的点，其左侧、下方都不满足条件
  1 2 3 4 5 6
1 x ------- o
2 x x
3 x x x 
4 x x x x
5 x x x x x
6 x x x x x x
*/

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int l = 0, r = -1, sum = 0, ans = INT32_MAX;
        for (; l < nums.size(); ) {
            if (r + 1 < nums.size() && sum < s) // 注意.size()返回是unsigned int，故写成 r < nums.size()-1 会出错
                sum += nums[++r];
            else
                sum -= nums[l++];

            if (sum >= s)
                ans = min(ans, r-l+1);
            else if (r == nums.size() - 1)
                break;
        }
        if (ans > nums.size())
            return 0;
        return ans;
    }
};

int main() {
    int arr[] = {1,2,3,4,5}, s = 15;
    vector<int> nums(arr, arr + sizeof(arr)/sizeof(int));

    cout << Solution().minSubArrayLen(s, nums) << endl;

    return 0;
}