import java.util.Arrays;

// Space optimization
class Solution {
    private int[][] apples;

    public int ways(String[] pizza, int k) {
        int m = pizza.length;
        int n = pizza[0].length();
        int[][] dp = new int[m][n];

        apples = new int[m + 1][n + 1];
        for (int i = m - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                apples[i][j] = (pizza[i].charAt(j) == 'A' ? 1 : 0) + apples[i + 1][j] + apples[i][j + 1] - apples[i + 1][j + 1];
                dp[i][j] = apples[i][j] > 0 ? 1 : 0;
            }
        }

        int MOD = 1000000007;
        for (int remain = 1; remain < k; ++remain) {
            int[][] new_dp = new int[m][n];
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                    for (int next_row = i + 1; next_row < m; ++next_row) {
                        if (apples[i][j] - apples[next_row][j] > 0) {
                            new_dp[i][j] += dp[next_row][j];
                            new_dp[i][j] %= MOD;
                        }
                    }
                    for (int next_col = j + 1; next_col < n; ++next_col) {
                        if (apples[i][j] - apples[i][next_col] > 0) {
                            new_dp[i][j] += dp[i][next_col];
                            new_dp[i][j] %= MOD;
                        }
                    }
                }
            }
            // dp = Arrays.stream(new_dp).map(int[]::clone).toArray(int[][]::new);
            dp = new_dp.clone();
        }

        return dp[0][0];
    }
}

public class Main2 {
    public static void main(String[] args) {
        String[] pizza = {"A..","AAA","..."};
        int k = 3;
        int res = new Solution().ways(pizza, k);
        System.out.println(res);
    }
}
