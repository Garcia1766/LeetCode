class Solution {
    public void reverseWords(char[] s) {
        int n = s.length;
        reversePart(s, 0, n - 1);

        int l = 0, r = 0;
        while (l < n) {
            if (r == n || s[r] == ' ') {
                reversePart(s, l, r - 1);
                l = r + 1;
            }
            r++;
        }
    }

    void reversePart(char[] s, int l, int r) {
        for (int i = l; i <= ((l + r) >> 1); ++i) {
            char tmp = s[i];
            s[i] = s[l + r - i];
            s[l + r - i] = tmp;
        }
    }
}

public class Main {
    public static void main(String[] args) {
        char[] s = {'t','h','e',' ','s','k','y',' ','i','s',' ','b','l','u','e'};
        new Solution().reverseWords(s);
        System.out.println(s);
    }
}
