import java.util.Arrays;

class Solution {
    public int findContentChildren(int[] g, int[] s) {
        Arrays.sort(g);
        Arrays.sort(s);

        int si = 0, gi = 0;
        int res = 0;
        while (si < s.length && gi < g.length) {
            if (s[si] >= g[gi]) {
                ++res;
                ++si;
                ++gi;
            } else {
                ++si;
            }
        }
        return res;
    }
}

public class Main {
    public static void main(String[] args) {
        int[] g = {1, 2};
        int[] s = {1, 2, 3};
        int res = new Solution().findContentChildren(g, s);
        System.out.println(res);
    }
}
