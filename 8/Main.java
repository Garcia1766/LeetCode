class Solution {
    public int myAtoi(String s) {
        return 0;
    }
}

public class Main {
    public static void main(String[] args) {
        String s = "   -42";
        int res = new Solution().myAtoi(s);
        System.out.println(res);
    }
}
