class Solution {
    private void print_arr(int[][] dp) {
        for (int[] l : dp) {
            for (int v : l) {
                System.out.printf("%d ", v);
            }
            System.out.println();
        }
    }

    public int superEggDrop(int k, int n) {
        int[][] dp = new int[k + 1][n + 1];
        for (int i = 1; i <= n; ++i) {
            dp[1][i] = i;
        }
        for (int i = 2; i <= k; ++i) {
            dp[i][1] = 1;
        }

        for (int i = 2; i <= k; ++i) {
            for (int j = 2; j <= n; ++j) {
                // binary search
                int lo = 1, hi = j;
                int pos = (lo + hi) >> 1;
                while (hi - lo > 1) {
                    if (dp[i - 1][pos - 1] < dp[i][j - pos]) {
                        lo = pos;
                    } else if (dp[i - 1][pos - 1] > dp[i][j - pos]) {
                        hi = pos;
                    } else {
                        lo = pos;
                        hi = pos;
                    }
                    pos = (lo + hi) >> 1;
                }
                dp[i][j] = 1 + Math.min(Math.max(dp[i - 1][lo - 1], dp[i][j - lo]), Math.max(dp[i - 1][hi - 1], dp[i][j - hi]));
            }
        }

        return dp[k][n];
    }
}

public class Main {
    public static void main(String[] args) {
        int k = 2, n = 9;
        int res = new Solution().superEggDrop(k, n);
        System.out.println(res);
    }
}
