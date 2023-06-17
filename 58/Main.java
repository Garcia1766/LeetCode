class Solution {
    public int lengthOfLastWord(String s) {
        int n = s.length();
        int pos = n - 1;
        int res = 0;
        for (; pos >= 0 && s.charAt(pos) == ' '; pos--);
        for (; pos >= 0 && s.charAt(pos) != ' '; pos--) {
            res++;
        }
        return res;
    }
}

public class Main {
    public static void main(String[] args) {
        String s = "   fly me   to   the moon  ";
        int res = new Solution().lengthOfLastWord(s);
        System.out.println(res);
    }
}
