class Solution {
    public boolean isSubsequence(String s, String t) {
        int si = 0, ti = 0;
        while (si < s.length() && ti < t.length()) {
            if (s.charAt(si) == t.charAt(ti)) {
                ++si;
            }
            ++ti;
        }
        return si >= s.length();
    }
}

public class Main {
    public static void main(String[] args) {
        String s = "axc", t = "ahbgdc";
        boolean res = new Solution().isSubsequence(s, t);
        System.out.println(res);
    }
}
