class Solution {
    public int[][] generateMatrix(int n) {
        int[][] res = new int[n][n];
        int up = 0, down = n - 1, left = 0, right = n - 1;
        int curNum = 1;
        while (curNum <= n * n) {
            for (int j = left; j <= right; ++j) {
                res[up][j] = curNum++;
            }
            for (int i = up + 1; i <= down; ++i) {
                res[i][right] = curNum++;
            }
            if (up < down) {
                for (int j = right - 1; j >= left; --j) {
                    res[down][j] = curNum++;
                }
            }
            if (left < right) {
                for (int i = down - 1; i > up; --i) {
                    res[i][left] = curNum++;
                }
            }
            up++; down--; left++; right--;
        }
        return res;
    }
}

public class Main {
    public static void main(String[] args) {
        int n = 3;
        int[][] res = new Solution().generateMatrix(n);
        for (int i = 0; i < res.length; ++i) {
            for (int j = 0; j < res[0].length; ++j) {
                System.out.printf("%d,", res[i][j]);
            }
            System.out.println();
        }
        System.out.println();
    }
}
