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

        int[][] dp = new int[m + 1][n + 1];  // default init value = 0

        for (int i = 1; i < l + 1; ++i) {
            // Update in this order can avoid using old_dp[][]. Because every cell is updated based only on the last layer
            for (int j = m; j >= 0; --j) {
                for (int k = n; k >= 0; --k) {
                    if (stri[i - 1][0] <= j && stri[i - 1][1] <= k) {
                        dp[j][k] = Math.max(dp[j][k], dp[j - stri[i - 1][0]][k - stri[i - 1][1]] + 1);
                    }
                }
            }
        }

        return dp[m][n];
    }
}

public class TimeOpt {
    public static void main(String[] args) {
        String[] strs = {"10","0001","111001","1","0"};
        int m = 5;
        int n = 3;
        int res = new Solution().findMaxForm(strs, m, n);
        System.out.println(res);
    }
}
