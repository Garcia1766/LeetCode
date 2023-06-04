class Solution {
    public int strStr(String haystack, String needle) {
        int pos = 0;
        int n = haystack.length(), m = needle.length();
        for (; pos <= n - m; ++pos) {
            if (haystack.charAt(pos) == needle.charAt(0)){
                boolean flag = true;
                for (int j = 1; j < m; ++j) {
                    if (haystack.charAt(pos + j) != needle.charAt(j)){
                        flag = false;
                        break;
                    }
                }
                if (flag) {
                    return pos;
                }
            }
        }
        return -1;
    }
}

public class Main {
    public static void main(String[] args) {
        String haystack = "sadbutsad", needle = "sad";
        int res = new Solution().strStr(haystack, needle);
        System.out.println(res);
    }
}
