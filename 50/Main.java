class Solution {
    // use long to avoid overflow(-2^31)
    private double savelyMyPower(double x, long n) {
        if (n == 0) return 1;
        int sign = n > 0 ? 1 : -1;
        n = Math.abs(n);

        double res = 1;

        while (n > 0) {
            if (n % 2 != 0) {
                n--;
                res *= x;
            }
            n /= 2;
            x = x * x;
        }

        return sign == 1 ? res : 1 / res;
    }

    public double myPow(double x, int n) {
        return savelyMyPower(x, (long) n);
    }
}

public class Main {
    public static void main(String[] args) {
        double x = 2.00000;
        int n = 10;
        double res = new Solution().myPow(x, n);
        System.out.println(res);
    }
}
