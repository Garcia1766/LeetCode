class Solution {
    public int mySqrt(int x) {
        if (x == 0) return 0;
        if (x >= 1 && x <= 3) return 1;
        if (x >= 4 && x <= 8) return 2;

        int l = 3, r = x / 2, mid = (l + r) >> 1;
        while (r - l > 1) {
            if (mid <= 46340 && mid * mid <= x) { // Use "long" can avoid 46340
                l = mid;
            } else {
                r = mid;
            }
            mid = (l + r) >> 1;
        }

        return l;
    }
}

public class Main {
    public static void main(String[] args) {
        int x = 120;
        int res = new Solution().mySqrt(x);
        System.out.println(res);
    }
}
