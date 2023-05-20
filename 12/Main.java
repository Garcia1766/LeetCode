class Solution {
    public String intToRoman(int num) {
        StringBuilder sbd = new StringBuilder();
        for (; num >= 1000; num -= 1000) {
            sbd.append('M');
        }

        if (num >= 900) {
            sbd.append("CM");
            num -= 900;
        }
        if (num >= 500) {
            sbd.append('D');
            num -= 500;
        }
        if (num >= 400) {
            sbd.append("CD");
            num -= 400;
        }
        for (; num >= 100; num -= 100) {
            sbd.append('C');
        }

        if (num >= 90) {
            sbd.append("XC");
            num -= 90;
        }
        if (num >= 50) {
            sbd.append('L');
            num -= 50;
        }
        if (num >= 40) {
            sbd.append("XL");
            num -= 40;
        }
        for (; num >= 10; num -= 10) {
            sbd.append('X');
        }

        if (num >= 9) {
            sbd.append("IX");
            num -= 9;
        }
        if (num >= 5) {
            sbd.append('V');
            num -= 5;
        }
        if (num >= 4) {
            sbd.append("IV");
            num -= 4;
        }
        for (; num >= 1; num -= 1) {
            sbd.append('I');
        }

        return sbd.toString();
    }
}

public class Main {
    public static void main(String[] args) {
        int num = 1994;
        String res = new Solution().intToRoman(num);
        System.out.println(res);
    }
}
