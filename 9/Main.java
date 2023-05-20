class Solution {
    public boolean isPalindrome(int x) {
        if (x < 0) return false;
        if (x >= 0 && x <= 9) return true;

        String s = String.valueOf(x);
        int n = s.length();
        int l = 0, r = n - 1;
        while (l < n / 2) {
            if (s.charAt(l) != s.charAt(r)) {
                return false;
            }
            ++l;
            --r;
        }
        return true;
    }
}

public class Main {
    public static void main(String[] args) {
        int x = 12121;
        boolean res = new Solution().isPalindrome(x);
        System.out.println(res);
    }
}
