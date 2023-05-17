class Solution {
    private int expandAroundCenter(String s, int left, int right) {
        int n = s.length();
        int L = left, R = right;
        while (L >= 0 && R < n && s.charAt(L) == s.charAt(R)) {
            --L;
            ++R;
        }
        return R - L - 1;
    }

    public String longestPalindrome(String s) {
        int n = s.length();
        int start = 0, end = 0;
        for (int i = 0; i < n; ++i) {
            int len1 = expandAroundCenter(s, i, i);
            int len2 = expandAroundCenter(s, i, i + 1);
            int len = Math.max(len1, len2);
            if (len > end - start) {
                start = i - (len - 1) / 2;
                end = i + len / 2 + 1;
            }
        }

        return s.substring(start, end);
    }
}

public class Main {
    public static void main(String[] args) {
        String s = "aacabdkacaa";
        String res = new Solution().longestPalindrome(s);
        System.out.println(res);
    }
}
