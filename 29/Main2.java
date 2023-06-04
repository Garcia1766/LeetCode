// O(log n)
class Solution {
    public int divide(int dividend, int divisor) {
        if (dividend == 0) return 0;

        if (divisor == Integer.MIN_VALUE) return (dividend == Integer.MIN_VALUE) ? 1 : 0;

        if (dividend == Integer.MIN_VALUE && divisor == -1) return Integer.MAX_VALUE;

        int negative = 2;  // num of negative
        if (dividend > 0) {
            negative--;
            dividend = -dividend;
        }
        if (divisor > 0) {
            negative--;
            divisor = -divisor;
        }

        int res = 0, div = divisor, tmp = 1;
        if (dividend <= divisor) {
            while ((dividend != -1) && (dividend >> 1 < div)) {
                div <<= 1;
                tmp <<= 1;
            }
            dividend -= div;
            res += tmp;
        }

        while (tmp >= 1) {
            if (dividend <= div) {
                dividend -= div;
                res += tmp;
            }
            div >>= 1;
            tmp >>= 1;
        }

        return (negative == 1) ? -res : res;
    }
}

public class Main2 {
    public static void main(String[] args) {
        int dividend = -1024, divisor = 2;
        int res = new Solution().divide(dividend, divisor);
        System.out.println(res);
    }
}
