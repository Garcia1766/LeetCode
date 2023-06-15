import java.util.ArrayList;
import java.util.List;

class Solution {
    public List<Integer> spiralOrder(int[][] matrix) {
        int m = matrix.length, n = matrix[0].length;
        int up = 0, down = m - 1, left = 0, right = n - 1;
        List<Integer> res = new ArrayList<>();
        while (res.size() < m * n) {
            for (int j = left; j <= right; ++j) {
                res.add(matrix[up][j]);
            }
            for (int i = up + 1; i <= down; ++i) {
                res.add(matrix[i][right]);
            }
            if (up < down) {
                for (int j = right - 1; j >= left; --j) {
                    res.add(matrix[down][j]);
                }
            }
            if (left < right) {
                for (int i = down - 1; i > up; --i) {
                    res.add(matrix[i][left]);
                }
            }
            up++;
            down--;
            left++;
            right--;
        }
        return res;
    }
}

public class Main {
    public static void printMatrix(int[][] matrix) {
        int m = matrix.length, n = matrix[0].length;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                System.out.printf("%d,", matrix[i][j]);
            }
            System.out.println();
        }
        System.out.println();
    }

    public static void main(String[] args) {
        int[][] matrix = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
        List<Integer> res = new Solution().spiralOrder(matrix);
        System.out.println(res);
    }
}
