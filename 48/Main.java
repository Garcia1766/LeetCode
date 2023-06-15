class Solution {
    public void rotate(int[][] matrix) {
        int n = matrix.length;
        if (n == 1) return;
        
        for (int i = 0; i < n / 2; ++i) {
            for (int j = 0; j < (n + 1) / 2; ++j) {
                int[] x = {i, j, n - 1 - i, n - 1 - j};
                int[] y = {j, n - 1 - i, n - 1 - j, i};
                int tmp = matrix[x[0]][y[0]];
                matrix[x[0]][y[0]] = matrix[x[3]][y[3]];
                matrix[x[3]][y[3]] = matrix[x[2]][y[2]];
                matrix[x[2]][y[2]] = matrix[x[1]][y[1]];
                matrix[x[1]][y[1]] = tmp;
            }
        }
    }

    // Transpose + reverse = rotate
    public void rotate2(int[][] matrix) {
        int n = matrix.length;
        if (n == 1) return;
        
        for (int i = 0; i < n - 1; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = tmp;
            }
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n / 2; ++j) {
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[i][n - 1 - j];
                matrix[i][n - 1 - j] = tmp;
            }
        }
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
        int[][] matrix = {{5,1,9,11},{2,4,8,10},{13,3,6,7},{15,14,12,16}};
        printMatrix(matrix);
        new Solution().rotate(matrix);
        printMatrix(matrix);
    }
}
