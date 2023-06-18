// Another solution: use matrix[i][0] and matrix[0][j] as indicators. O(1) Space
import java.util.HashSet;
import java.util.Set;

class Solution {
    public void setZeroes(int[][] matrix) {
        int m = matrix.length, n = matrix[0].length;
        Set<Integer> rows = new HashSet<>(m);
        Set<Integer> cols = new HashSet<>(n);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == 0) {
                    rows.add(i);
                    cols.add(j);
                }
            }
        }
        for (Integer r : rows) {
            for (int j = 0; j < n; ++j) {
                matrix[r][j] = 0;
            }
        }
        for (Integer c : cols) {
            for (int i = 0; i < m; ++i) {
                matrix[i][c] = 0;
            }
        }
    }
}

public class Main {
    public static void printMatrix(int[][] mat) {
        for (int i = 0; i < mat.length; ++i) {
            for (int j = 0; j < mat[0].length; ++j) {
                System.out.printf("%d,", mat[i][j]);
            }
            System.out.println();
        }
        System.out.println();
    }

    public static void main(String[] args) {
        int[][] matrix = {{0,1,2,0},{3,4,5,2},{1,3,1,5}};
        new Solution().setZeroes(matrix);
        printMatrix(matrix);
    }
}
