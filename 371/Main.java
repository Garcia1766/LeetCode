class Solution {
    public int getSum(int a, int b) {
        int x = Math.abs(a), y = Math.abs(b);
        if (x < y) return getSum(b, a);

        int sign = a >= 0 ? 1 : -1;

        if (a * b >= 0) { // x + y
            while (y != 0) {
                int sum = x ^ y;
                int carry = (x & y) << 1;
                x = sum;
                y = carry;
            }
        } else { // x - y
            while (y != 0) {
                int sum = x ^ y;
                int borrow = ((~x) & y) << 1;
                x = sum;
                y = borrow;
            }
        }
        return x * sign;
    }
}

public class Main {
    public static void main(String[] args) {
        int a = 2, b = 3;
        int res = new Solution().getSum(a, b);
        System.out.println(res);
    }
}

