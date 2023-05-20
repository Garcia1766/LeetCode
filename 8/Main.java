class Solution {
    public int myAtoi(String s) {
        if (s.length() == 0) return 0;

        int n = s.length();
        int cur_pos = 0;
        for (; cur_pos < n && s.charAt(cur_pos) == ' '; ++cur_pos);
        if (cur_pos >= n) return 0;

        char sign;
        if (s.charAt(cur_pos) == '+' || s.charAt(cur_pos) =='-') {
            sign = s.charAt(cur_pos);
            ++cur_pos;
        } else {
            sign = '+';
        }

        int res = 0, negative = 0;
        while (cur_pos < n && '0' <= s.charAt(cur_pos) && s.charAt(cur_pos) <= '9' && res < Integer.MAX_VALUE) {
            if (res > Integer.MAX_VALUE / 10) {
                res = Integer.MAX_VALUE;
                if (sign == '-') {
                    negative = 1;
                }
            } else if (res < Integer.MAX_VALUE / 10) {
                res = res * 10 + (s.charAt(cur_pos) - '0');
            } else { // res == Integer.MAX_VALUE / 10
                if (s.charAt(cur_pos) <= '7') {
                    res = res * 10 + (s.charAt(cur_pos) - '0');
                } else { // s.charAt(cur_pos) >= '8'
                    res = Integer.MAX_VALUE;
                    if (sign == '-') {
                        negative = 1;
                    }
                }
            }
            ++cur_pos;
        }

        if (sign == '-' && negative == 1) {
            return -Integer.MAX_VALUE - 1;
        } else {
            return sign == '-' ? -res : res;
        }
    }
}

public class Main {
    public static void main(String[] args) {
        String s = "4193 with words";
        int res = new Solution().myAtoi(s);
        System.out.println(res);
    }
}
