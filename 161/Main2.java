class Solution {
    public boolean isOneEditDistance(String s, String t) {
        if (s.length() > t.length()) return isOneEditDistance(t, s);

        int m = s.length(), n = t.length(); // m <= n
        if (n - m > 1) return false;

        int i = 0, j = 0, flag = 0;
        while (i < m && j < n) {
            if (s.charAt(i) != t.charAt(j)) {
                if (flag >= 1) return false;
                if (n - m == 1) {
                    j++;
                } else {
                    i++; j++;
                }
                flag++;
                continue;
            }
            i++; j++;
        }
        if (j < n) flag++;
        return flag == 1;
    }
}

public class Main2 {
    public static void main(String[] args) {
        return;
    }
}
