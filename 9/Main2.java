class Solution {
    public boolean isPalindrome(int x) {
        if (x < 0) return false;
        if (x >= 0 && x <= 9) return true;
        if (x % 10 == 0) return false;

        int left = x, right = 0;
        while (left > right) {
            int cur_digit = left % 10;
            left /= 10;
            right = right * 10 + cur_digit;
        }
        
        return left == right || left == right / 10;
    }
}

public class Main2 {
    public static void main(String[] args) {
        int x = 121210;
        boolean res = new Solution().isPalindrome(x);
        System.out.println(res);
    }
}
