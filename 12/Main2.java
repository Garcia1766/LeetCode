class Solution {
    public String intToRoman(int num) {
        String[] symbols = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        int[] values = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        StringBuilder sbd = new StringBuilder();
        for (int i = 0; i < symbols.length; ++i) {
            while (num >= values[i]) {
                sbd.append(symbols[i]);
                num -= values[i];
            }
        }

        return sbd.toString();
    }
}

public class Main2 {
    public static void main(String[] args) {
        int num = 1994;
        String res = new Solution().intToRoman(num);
        System.out.println(res);
    }
}
