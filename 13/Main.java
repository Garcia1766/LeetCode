class Solution {
    public int romanToInt(String s) {
        String[] symbols = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        int[] values = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        int res = 0;
        int cur_pos = 0;
        for (int i = 0; i < symbols.length && cur_pos < s.length(); ++i) {
            while (cur_pos < s.length() && symbols[i].equals(s.substring(cur_pos, cur_pos + 1))) {
                res += values[i];
                cur_pos += 1;
            }
            if (cur_pos < s.length() - 1) {
                while (cur_pos < s.length() - 1 && symbols[i].equals(s.substring(cur_pos, cur_pos + 2))) {
                    res += values[i];
                    cur_pos += 2;
                }
            }
        }

        return res;
    }
}

public class Main {
    public static void main(String[] args) {
        String s = "DCXXI";
        int res = new Solution().romanToInt(s);
        System.out.println(res);
    }
}
