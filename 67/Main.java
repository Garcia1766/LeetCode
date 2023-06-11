class Solution {
    public String addBinary(String a, String b) {
        int m = a.length(), n = b.length(), l = Math.max(m, n) + 1;
        char[] res = new char[l];
        for (int i = 0; i < l; ++i) {
            res[i] = '0';
        }
        int i = 0, j = 0, k = 0;
        int carry = 0;
        while (i < m && j < n) {
            int tmp = (a.charAt(m - 1 - i) - '0') + (b.charAt(n - 1 - j) - '0') + carry;
            if (tmp == 0) {
                res[l - 1 - k] = '0';
            } else if (tmp == 1) {
                res[l - 1 - k] = '1';
                carry = 0;
            } else if (tmp == 2) {
                res[l - 1 - k] = '0';
                carry = 1;
            } else { // tmp == 3
                res[l - 1 - k] = '1';
                carry = 1;
            }
            i++; j++; k++;
        }
        while (i < m) {
            int tmp = (a.charAt(m - 1 - i) - '0') + carry;
            if (tmp == 0) {
                res[l - 1 - k] = '0';
            } else if (tmp == 1) {
                res[l - 1 - k] = '1';
                carry = 0;
            } else { // tmp == 2
                res[l - 1 - k] = '0';
                carry = 1;
            }
            i++; k++;
        }
        while (j < n) {
            int tmp = (b.charAt(n - 1 - j) - '0') + carry;
            if (tmp == 0) {
                res[l - 1 - k] = '0';
            } else if (tmp == 1) {
                res[l - 1 - k] = '1';
                carry = 0;
            } else { // tmp == 2
                res[l - 1 - k] = '0';
                carry = 1;
            }
            j++; k++;
        }
        if (carry == 1) {
            res[l - 1 - k] = '1';
        }
        
        if (res[0] == '1') {
            return new String(res);
        } else {
            return new String(res, 1, res.length - 1);
        }
    }
}

public class Main {
    public static void main(String[] args) {
        String a = "1010", b = "1011";
        String res = new Solution().addBinary(a, b);
        System.out.println(res);
    }
}

