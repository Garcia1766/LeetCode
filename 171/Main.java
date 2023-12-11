class Solution {
    public int titleToNumber(String columnTitle) {
        int res = 0;
        int pos = 0;
        while (pos < columnTitle.length()) {
            res = res * 26 + (columnTitle.charAt(pos) - 'A' + 1);
            pos++;
        }
        return res;
    }
}

public class Main {
    public static void main(String[] args) {
        String columnTitle = "ZY";
        int res = new Solution().titleToNumber(columnTitle);
        System.out.println(res);
    }
}
