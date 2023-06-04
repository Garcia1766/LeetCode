// O(log^2 n)
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

        int res = 0;
        while (dividend <= divisor) {
            int div = divisor, tmp = 1;
            while ((dividend != -1) && (dividend >> 1 < div)) {
                div = div << 1;
                tmp = tmp << 1;
            }
            dividend -= div;
            res += tmp;
        }

        return (negative == 1) ? -res : res;
    }
}

public class Main {
    public static void main(String[] args) {
        int dividend = Integer.MAX_VALUE, divisor = 1;
        int res = new Solution().divide(dividend, divisor);
        System.out.println(res);
    }
}
