class Solution {
    private int[] buildNext(String needle) {
        int m = needle.length();
        int[] next = new int[m];
        int j = 0;
        int t = next[0] = -1;

        while (j < m - 1) {
            if (t < 0 || needle.charAt(j) == needle.charAt(t)) {
                ++j;
                ++t;
                if (needle.charAt(j) != needle.charAt(t)) {
                    next[j] = t;
                } else {
                    next[j] = next[t];
                }
            } else {
                t = next[t];
            }
        }

        return next;
    }

    public int strStr(String haystack, String needle) {
        int n = haystack.length(), m = needle.length();
        int[] next = buildNext(needle);
        int i = 0, j = 0;

        while (i < n && j < m) {
            if (j == -1 || haystack.charAt(i) == needle.charAt(j)) {
                ++i;
                ++j;
            } else {
                j = next[j];
            }
        }
        if (j >= m) return i - j;

        return -1;
    }
}

public class Kmp {
    public static void main(String[] args) {
        String haystack = "aaa", needle = "aaa";
        int res = new Solution().strStr(haystack, needle);
        System.out.println(res);
    }
}
