class Solution {
    public int[] plusOne(int[] digits) {
        int n = digits.length;
        int pos = n - 1;
        while (pos >= 0 && digits[pos] == 9) {
            pos--;
        }
        if (pos >= 0) {
            digits[pos] += 1;
            for (int i = pos + 1; i < n; ++i) {
                digits[i] = 0;
            }
        } else { // pos = -1
            int[] res = new int[n + 1];
            res[0] = 1;
            for (int i = 1; i < n + 1; ++i) {
                res[i] = 0;
            }
            return res;
        }
        return digits;
    }
}

public class Main {
    public static void main(String[] args) {
        int[] digits = {1,2,3};
        int[] res = new Solution().plusOne(digits);
        for (int num : res) {
            System.out.printf("%d,", num);
        }
        System.out.println();
    }
}
