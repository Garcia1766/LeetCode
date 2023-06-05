class Solution {
    public String countAndSay(int n) {
        String curStr = "1";

        for (int i = 2; i <= n; ++i) {
            StringBuilder nextSbd = new StringBuilder();
            for (int j = 0, k = 0; j < curStr.length(); j = k) {
                while (k < curStr.length() && curStr.charAt(j) == curStr.charAt(k)) {
                    ++k;
                }
                // 尽量避免String直接相加。下两句若写成
                // nextSbd.append(String.valueOf(k - j) + curStr.charAt(j))
                // 速度会慢很多
                nextSbd.append(String.valueOf(k - j));
                nextSbd.append(curStr.charAt(j));
            }
            curStr = nextSbd.toString();
        }
        return curStr;
    }
}

public class Main {
    public static void main(String[] args) {
        int n = 4;
        String res = new Solution().countAndSay(n);
        System.out.println(res);
    }
}
