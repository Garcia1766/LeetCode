class Solution {
    public String addStrings(String num1, String num2) {
        int l1 = num1.length(), l2 = num2.length();
        if (l1 < l2) return addStrings(num2, num1);
        // l1 >= l2
        StringBuilder sbd = new StringBuilder();
        int i = l1 - 1, j = l2 - 1;
        int carry = 0;
        while (j >= 0) {
            int tmp = (num1.charAt(i) - '0') + (num2.charAt(j) - '0') + carry;
            carry = 0;
            if (tmp >= 10) {
                carry = 1;
                tmp -= 10;
            }
            sbd.append(String.valueOf(tmp));
            i--; j--;
        }
        while (i >= 0) {
            int tmp = (num1.charAt(i) - '0') + carry;
            carry = 0;
            if (tmp >= 10) {
                carry = 1;
                tmp -= 10;
            }
            sbd.append(String.valueOf(tmp));
            i--;
        }
        if (carry == 1) sbd.append('1');
        
        return sbd.reverse().toString();
    }
}

public class Main {
    public static void main(String[] args) {
        String num1 = "456", num2 = "77";
        String res = new Solution().addStrings(num1, num2);
        System.out.println(res);
    }
}

