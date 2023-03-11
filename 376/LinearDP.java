class Solution {
    public int wiggleMaxLength(int[] nums) {
        if (nums.length < 2) {
            return nums.length;
        }

        int[][] dp = new int[2][nums.length];
        for (int i = 0; i < nums.length; ++i) {
            dp[0][i] = 1;  // down state
            dp[1][i] = 1;  // up state
        }

        for (int i = 1; i < nums.length; ++i) {
            // not neccesarily contains nums[i]
            if (nums[i] < nums[i - 1]) {  // down state
                dp[0][i] = dp[1][i - 1] + 1;
                dp[1][i] = dp[1][i - 1];
            } else if (nums[i] > nums[i - 1]) {  // up state
                dp[1][i] = dp[0][i - 1] + 1;
                dp[0][i] = dp[0][i - 1];
            } else {
                dp[0][i] = dp[0][i - 1];
                dp[1][i] = dp[1][i - 1];
            }
        }
        return Math.max(dp[0][nums.length - 1], dp[1][nums.length - 1]);
    }
}

public class LinearDP {
    public static void main(String[] args) {
        int[] nums = {1,7,4,9,2,5};
        int res = new Solution().wiggleMaxLength(nums);
        System.out.println(res);
    }
}
