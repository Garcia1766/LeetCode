class Solution {
    public int maxSubArray(int[] nums) {
        int curSum = nums[0];
        int maxSum = nums[0];

        for (int i = 1; i < nums.length; ++i) {
            if (curSum < 0) {
                curSum = 0;
            }
            curSum += nums[i];
            if (curSum > maxSum) {
                maxSum = curSum;
            }
        }

        return maxSum;
    }
}

public class Main {
    public static void main(String[] args) {
        int[] nums = {-2,1,-3,4,-1,2,1,-5,4};
        int res = new Solution().maxSubArray(nums);
        System.out.println(res);
    }
}
