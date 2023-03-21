class Solution {
    public String shortestCommonSupersequence(String str1, String str2) {
        int m = str1.length();
        int n = str2.length();
        int[][] lcs = new int[m + 1][n + 1];
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (str1.charAt(i - 1) == str2.charAt(j - 1)) {
                    lcs[i][j] = 1 + lcs[i - 1][j - 1];
                } else {
                    lcs[i][j] = Math.max(lcs[i - 1][j], lcs[i][j - 1]);
                }
            }
        }

        String res = "";
        int i = m, j = n;
        while (i > 0 || j > 0) {
            if (i > 0 && j > 0) {
                if (str1.charAt(i - 1) == str2.charAt(j - 1)) {
                    res += str1.charAt(i - 1);
                    --i;
                    --j;
                } else if (lcs[i][j] == lcs[i - 1][j]) {
                    res += str1.charAt(i - 1);
                    --i;
                } else {  // lcs[i][j] == lcs[i][j - 1]
                    res += str2.charAt(j - 1);
                    --j;
                }
            } else if (i > 0) {
                res += str1.charAt(i - 1);
                --i;
            } else {  // j > 0
                res += str2.charAt(j - 1);
                --j;
            }
        }

        return new StringBuffer(res).reverse().toString();
    }
}

public class Main {
    public static void main(String[] args) {
        String str1 = "abac", str2 = "cab";
        String res = new Solution().shortestCommonSupersequence(str1, str2);
        System.out.println(res);
    }
}
