class Solution {
    public int reverse(int x) {
        if (x == 0) return 0;
        int ans = 0;
        int X = x > 0 ? x : -x;
        int left_digits = X;
        while (left_digits > 0) {
            int cur_digit = left_digits % 10;
            left_digits /= 10;
            if (ans > Integer.MAX_VALUE / 10) {
                return 0;
            } else if (ans == Integer.MAX_VALUE / 10) {
                if (cur_digit > 7) return 0;
            }
            ans = ans * 10 + cur_digit;
        }

        return x > 0 ? ans : -ans;
    }
}

public class Main {
    public static void main(String[] args) {
        int x = 120;
        int res = new Solution().reverse(x);
        System.out.println(res);
    }
}
