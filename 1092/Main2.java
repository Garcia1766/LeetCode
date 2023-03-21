class Solution {
    public String shortestCommonSupersequence(String str1, String str2) {
        int m = str1.length();
        int n = str2.length();
        String[][] lcs = new String[m + 1][n + 1];
        for (int i = 0; i <= m; ++i) {
            for (int j = 0; j <= n; ++j) {
                if (i == 0 || j == 0) {
                    lcs[i][j] = "";
                    continue;
                }
                if (str1.charAt(i - 1) == str2.charAt(j - 1)) {
                    lcs[i][j] = lcs[i - 1][j - 1] + str1.charAt(i - 1);
                } else {
                    lcs[i][j] = lcs[i - 1][j].length() > lcs[i][j - 1].length() ? lcs[i - 1][j] : lcs[i][j - 1];
                }
            }
        }
        String LCS = lcs[m][n];

        String res = "";
        int i = 0, j = 0;
        for (char c : LCS.toCharArray()) {
            while (str1.charAt(i) != c) {
                res += str1.charAt(i++);
            }
            while (str2.charAt(j) != c) {
                res += str2.charAt(j++);
            }
            res += c;
            ++i;
            ++j;
        }

        return res + str1.substring(i) + str2.substring(j);
    }
}

public class Main2 {
    public static void main(String[] args) {
        String str1 = "abac", str2 = "cab";
        String res = new Solution().shortestCommonSupersequence(str1, str2);
        System.out.println(res);
    }
}
