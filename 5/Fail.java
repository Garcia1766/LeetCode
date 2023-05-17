import java.util.ArrayList;

class CommonSubString {
    String substr;
    int pos1;
    int pos2;

    public CommonSubString(String s, int a, int b) {
        this.substr = s;
        this.pos1 = a;
        this.pos2 = b;
    }
}

class Solution {
    // fail when "aacabdkacaa"

    public ArrayList<CommonSubString> longestCommonSubString(String s, String t) {
        int m = s.length();
        int n = t.length();
        int[][] dp = new int[m][n];
        int len = 0;
        ArrayList<CommonSubString> res = new ArrayList<>();

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (s.charAt(i) == t.charAt(j)) {
                    if (i == 0 || j == 0) {
                        dp[i][j] = 1;
                    } else {
                        dp[i][j] = dp[i - 1][j - 1] + 1;
                    }

                    if (dp[i][j] > len) {
                        len = dp[i][j];
                        res.clear();
                        res.add(new CommonSubString(s.substring(i + 1 - len, i + 1), i + 1 - len, j + 1 - len));
                    } else if (dp[i][j] == len) {
                        res.add(new CommonSubString(s.substring(i + 1 - len, i + 1), i + 1 - len, j + 1 - len));
                    }
                } else {
                    dp[i][j] = 0;
                }
            }
        }

        return res;
    }

    public String longestPalindrome(String s) {
        int n = s.length();
        StringBuilder sbd = new StringBuilder(s);
        String t = sbd.reverse().toString();
        System.out.println(s);
        System.out.println(t);

        ArrayList<CommonSubString> commonSubStrings = longestCommonSubString(s, t);
        for (int i = 0; i < commonSubStrings.size(); ++i) {
            System.out.printf("%s %d %d\n", commonSubStrings.get(i).substr, commonSubStrings.get(i).pos1, commonSubStrings.get(i).pos2);
            if (commonSubStrings.get(i).pos1 + commonSubStrings.get(i).pos2 + commonSubStrings.get(i).substr.length() == n) {
                return commonSubStrings.get(i).substr;
            }
        }

        return "";
    }
}

public class Fail {
    public static void main(String[] args) {
        String s = "aacabdkacaa";
        String res = new Solution().longestPalindrome(s);
        System.out.println(res);
    }
}
