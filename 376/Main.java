class Solution {
    public int wiggleMaxLength(int[] nums) {
        int[][] dp = new int[2][nums.length];
        for (int i = 0; i < nums.length; ++i) {
            dp[0][i] = 1;
            dp[1][i] = 1;
        }
        for (int i = 1; i < nums.length; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[j] < nums[i]) {
                    dp[1][i] = Math.max(dp[1][i], dp[0][j] + 1);
                } else if (nums[j] > nums[i]) {
                    dp[0][i] = Math.max(dp[0][i], dp[1][j] + 1);
                }
            }
        }
        int res = 1;
        for (int i = 1; i < nums.length; ++i) {
            res = Math.max(res, dp[0][i]);
            res = Math.max(res, dp[1][i]);
        }
        return res;
    }
}

public class Main {
    public static void main(String[] args) {
        int[] nums = {1,7,4,9,2,5};
        int res = new Solution().wiggleMaxLength(nums);
        System.out.println(res);
    }
}
