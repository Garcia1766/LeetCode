class Solution {
    public String reverseWords(String s) {
        int n = s.length();
        StringBuilder sbd = new StringBuilder();
        int curTail = n, curStart = n - 1;
        while (curStart >= -1) {
            if (curStart >= 0 && s.charAt(curStart) != ' ') {
                curStart--;
            } else { // s.charAt(curStart) == ' '
                if (curStart + 1 < curTail) sbd.append(s.substring(curStart + 1, curTail) + " ");
                curTail = curStart;
                curStart--;
            }
        }
        if (sbd.charAt(sbd.length() - 1) == ' ') sbd.deleteCharAt(sbd.length() - 1);
        return sbd.toString();
    }
}

public class Main {
    public static void main(String[] args) {
        String s = "  hello world  ";
        String res = new Solution().reverseWords(s);
        System.out.println(res);
        return;
    }
}
