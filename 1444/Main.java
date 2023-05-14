class Solution {
    private int[][] apples;

    public int ways(String[] pizza, int k) {
        int m = pizza.length;
        int n = pizza[0].length();
        int[][][] dp = new int[k][m][n];

        apples = new int[m + 1][n + 1];
        for (int i = m - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                apples[i][j] = (pizza[i].charAt(j) == 'A' ? 1 : 0) + apples[i + 1][j] + apples[i][j + 1] - apples[i + 1][j + 1];
                dp[0][i][j] = apples[i][j] > 0 ? 1 : 0;
            }
        }

        int MOD = 1000000007;
        for (int remain = 1; remain < k; ++remain) {
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                    for (int next_row = i + 1; next_row < m; ++next_row) {
                        if (apples[i][j] - apples[next_row][j] > 0) {
                            dp[remain][i][j] += dp[remain - 1][next_row][j];
                            dp[remain][i][j] %= MOD;
                        }
                    }
                    for (int next_col = j + 1; next_col < n; ++next_col) {
                        if (apples[i][j] - apples[i][next_col] > 0) {
                            dp[remain][i][j] += dp[remain - 1][i][next_col];
                            dp[remain][i][j] %= MOD;
                        }
                    }
                }
            }
        }

        return dp[k - 1][0][0];
    }
}

public class Main {
    public static void main(String[] args) {
        String[] pizza = {"A..","AAA","..."};
        int k = 3;
        int res = new Solution().ways(pizza, k);
        System.out.println(res);
    }
}
