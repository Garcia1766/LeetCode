class Solution {
    public void printMatrix(int[][] mat) {
        for (int i = 0; i < mat.length; ++i) {
            for (int j = 0; j < mat[0].length; ++j) {
                System.out.printf("%d,", mat[i][j]);
            }
            System.out.println();
        }
        System.out.println();
    }

    public int minDistance(String word1, String word2) {
        int m = word1.length(), n = word2.length();
        int[][] dp = new int[m + 1][n + 1];
        for (int j = 0; j <= n; ++j) {
            dp[0][j] = j;
        }
        for (int i = 1; i <= m; ++i) {
            dp[i][0] = i;
        }
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (word1.charAt(i - 1) == word2.charAt(j - 1)) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = Math.min(dp[i - 1][j - 1] + 1, Math.min(dp[i][j - 1] + 1, dp[i - 1][j] + 1));
                }
            }
        }
        // printMatrix(dp);

        return dp[m][n];
    }
}

public class Main {
    public static void main(String[] args) {
        String word1 = "horse", word2 = "ros";
        int res = new Solution().minDistance(word1, word2);
        System.out.println(res);
    }
}
