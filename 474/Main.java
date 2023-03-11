import java.lang.Math;

class Solution {
    private void printStri(int[][] stri) {
        for (int[] p : stri) {
            System.out.printf("(%d,%d) ", p[0], p[1]);
        }
        System.out.println();
    }

    private void printDpLayer(int[][] dpLayer) {
        for (int[] li : dpLayer) {
            for (int num : li) {
                System.out.printf("%d ", num);
            }
            System.out.println();
        }
    }

    public int findMaxForm(String[] strs, int m, int n) {
        int l = strs.length;
        int[][] stri = new int[l][2];
        for (int i = 0; i < l; ++i) {
            stri[i][0] = (int)strs[i].chars().filter(c -> c == '0').count();
            stri[i][1] = (int)strs[i].chars().filter(c -> c == '1').count();
        }

        int[][][] dp = new int[l + 1][m + 1][n + 1];
        for (int i = 0; i < m + 1; ++i) {
            for (int j = 0; j < n + 1; ++j) {
                dp[0][i][j] = 0;
            }
        }
        for (int i = 1; i < l + 1; ++i) {
            dp[i][0][0] = 0;
        }

        for (int i = 1; i < l + 1; ++i) {
            for (int j = 0; j < m + 1; ++j) {
                for (int k = 0; k < n + 1; ++k) {
                    if (stri[i - 1][0] <= j && stri[i - 1][1] <= k) {
                        dp[i][j][k] = Math.max(dp[i - 1][j][k], dp[i - 1][j - stri[i - 1][0]][k - stri[i - 1][1]] + 1);
                    } else {
                        dp[i][j][k] = dp[i - 1][j][k];
                    }
                }
            }
        }

        return dp[l][m][n];
    }
}

public class Main {
    public static void main(String[] args) {
        String[] strs = {"10","0","1"};
        int m = 1;
        int n = 1;
        int res = new Solution().findMaxForm(strs, m, n);
        System.out.println(res);
    }
}
