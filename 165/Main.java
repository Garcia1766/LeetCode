class Solution {
    public int compareVersion(String version1, String version2) {
        String[] v1s = version1.split("\\.");
        String[] v2s = version2.split("\\.");
        int pos = 0;
        for (; pos < v1s.length && pos < v2s.length; ++pos) {
            if (Integer.valueOf(v1s[pos]) < Integer.valueOf(v2s[pos])) {
                return -1;
            } else if (Integer.valueOf(v1s[pos]) > Integer.valueOf(v2s[pos])) {
                return 1;
            }
        }

        if (v1s.length < v2s.length) {
            for (; pos < v2s.length; ++pos) {
                if (Integer.valueOf(v2s[pos]) > 0) return -1;
            }
        } else if (v1s.length > v2s.length) {
            for (; pos < v1s.length; ++pos) {
                if(Integer.valueOf(v1s[pos]) > 0) return 1;
            }
        }
        return 0;
    }
}


public class Main {
    public static void main(String[] args) {
        String version1 = "1.0", version2 = "1.0.0";
        int res = new Solution().compareVersion(version1, version2);
        System.out.println(res);
    }
}
