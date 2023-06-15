// O(n)
class Solution {
    public int jump(int[] nums) {
        int n = nums.length;
        if (n == 1) return 0;

        int ans = 0;
        int curEnd = 0, curFar = nums[0];
        for (int i = 0; i < n - 1; ++i) {
            if (i == curEnd) {
                ans++;
                curEnd = curFar;
            }
            curFar = Math.max(curFar, i + nums[i]);
        }
        return ans;
    }
}

public class Main2 {
    public static void main(String[] args) {
        int[] nums = {2,3,3,1,4};
        int res = new Solution().jump(nums);
        System.out.println(res);
    }
}
