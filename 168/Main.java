class Solution {
    public String convertToTitle(int columnNumber) {
        StringBuilder sbd = new StringBuilder();
        int residual = (columnNumber - 1) % 26;
        sbd.append((char)(residual + 'A'));
        int dividend = (columnNumber - 1) / 26;
        while (dividend != 0) {
            residual = (dividend - 1) % 26;
            sbd.append((char)(residual + 'A'));
            dividend = (dividend - 1) / 26;
        }
        return sbd.reverse().toString();
    }
}

public class Main {
    public static void main(String[] args) {
        int cn = 701;
        String res = new Solution().convertToTitle(cn);
        System.out.println(res);
    }
}
