class Solution {
    final int MOD = 1000000007;

    public int numRollsToTarget(int n, int k, int target) {
        int[][] dp = new int[n + 1][target + 1];
        for (int j = 1; j <= Math.min(target, k); ++j) {
            dp[1][j] = 1;
        }
        for (int i = 2; i <= n; ++i) {
            for (int j = 1; j <= target; ++j) {
                for (int l = 1; l <= Math.min(k, j); ++l) {
                    dp[i][j] = (dp[i][j] + dp[i - 1][j - l]) % MOD;
                }
            }
        }
        return dp[n][target];
    }
}

public class Main {
    public static void main(String[] args) {
        int n = 30, k = 30, target =500;
        int res = new Solution().numRollsToTarget(n, k, target);
        System.out.println(res);
    }
}
