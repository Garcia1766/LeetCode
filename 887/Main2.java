// O(KN) solution
// https://leetcode.com/problems/super-egg-drop/editorial/

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
            int x = 1;
            for (int j = 2; j <= n; ++j) {
                while (x < j && Math.max(dp[i - 1][x - 1], dp[i][j - x]) > Math.max(dp[i - 1][x], dp[i][j - x - 1])) {
                    ++x;
                }
                dp[i][j] = 1 + Math.max(dp[i - 1][x - 1], dp[i][j - x]);
            }
        }

        return dp[k][n];
    }
}

public class Main2 {
    public static void main(String[] args) {
        int k = 2, n = 9;
        int res = new Solution().superEggDrop(k, n);
        System.out.println(res);
    }
}
