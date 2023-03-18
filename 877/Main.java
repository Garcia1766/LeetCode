class Solution {
    public boolean stoneGame(int[] piles) {
        int n = piles.length;
        int dp[][] = new int[n + 2][n + 2];
        for (int l = 1; l <= n; ++l) {
            for (int i = 0; i + l <= n; ++i) {
                int j = i + l - 1;
                if ((i + j + n) % 2 == 1) {  // A
                    dp[i + 1][j + 1] = Math.max(piles[i] + dp[i + 2][j + 1], piles[j] + dp[i + 1][j]);
                } else {  // B
                    dp[i + 1][j + 1] = Math.min(-piles[i] + dp[i + 2][j + 1], -piles[j] + dp[i + 1][j]);
                }
            }
        }
        return dp[1][n] > 0;
    }
}

public class Main {
    public static void main(String[] args) {
        int[] nums = {5,3,4,5};
        boolean res = new Solution().stoneGame(nums);
        System.out.println(res);
    }
}
