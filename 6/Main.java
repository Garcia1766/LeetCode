class Solution {
    public String convert(String s, int numRows) {
        if (numRows == 1) return s;

        int n = s.length();
        StringBuilder sbd = new StringBuilder(); // Using StringBuilder is faster than using bare String

        for (int i = 0; i < numRows; ++i) {
            if (i == 0 || i == numRows - 1) {
                for (int j = i; j < n; j += 2 * (numRows - 1)) {
                    sbd.append(s.charAt(j));
                }
            } else { // 0 < i < K - 1
                for (int j = i; j < n; ) {
                    sbd.append(s.charAt(j));
                    j += 2 * (numRows - 1 - i);
                    if (j >= n)
                        break;
                    sbd.append(s.charAt(j));
                    j += 2 * i;
                }
            }
        }

        return sbd.toString();
    }
}

public class Main {
    public static void main(String[] args) {
        String s = "PAYPALISHIRING";
        int numRows = 3;
        String res = new Solution().convert(s, numRows);
        System.out.println(res);
    }
}
