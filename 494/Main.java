import java.util.Arrays;

class Solution {
    public int findTargetSumWays(int[] nums, int target) {
        int n = nums.length;
        int W = Arrays.stream(nums).sum();
        // int W = Math.max(target, (total + 1) / 2);
        int dp[][] = new int[n + 1][2 * W + 1];
        dp[0][W] = 1;
        for (int i = 1; i < n + 1; ++i) {
            for (int j = 0; j < 2 * W + 1; ++j) {
                if (j - nums[i - 1] >= 0 && j + nums[i - 1] <= 2 * W) {
                    dp[i][j] = dp[i - 1][j - nums[i - 1]] + dp[i - 1][j + nums[i - 1]];
                } else if (j - nums[i - 1] >= 0) {
                    dp[i][j] = dp[i - 1][j - nums[i - 1]];
                } else if (j + nums[i - 1] <= 2 * W) {
                    dp[i][j] = dp[i - 1][j + nums[i - 1]];
                }
            }
        }
        return Math.abs(target) > W ? 0 : dp[n][W + target];
    }
}

public class Main {
    public static void main(String[] args) {
        int[] nums = {1,1,1,1,1};
        int target = 3;
        int res = new Solution().findTargetSumWays(nums, target);
        System.out.println(res);
    }
}
