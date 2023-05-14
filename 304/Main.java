class NumMatrix {
    int[][] sumFrom;

    public NumMatrix(int[][] matrix) {
        int m = matrix.length;
        int n = matrix[0].length;
        sumFrom = new int[m + 1][n + 1];
        for (int i = m - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                sumFrom[i][j] = matrix[i][j] + sumFrom[i + 1][j] + sumFrom[i][j + 1] - sumFrom[i + 1][j + 1];
            }
        }
    }
    
    public int sumRegion(int row1, int col1, int row2, int col2) {
        return sumFrom[row1][col1] - sumFrom[row2 + 1][col1] - sumFrom[row1][col2 + 1] + sumFrom[row2 + 1][col2 + 1];
    }
}

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix obj = new NumMatrix(matrix);
 * int param_1 = obj.sumRegion(row1,col1,row2,col2);
 */

public class Main {
    public static void main(String[] args) {
        int[][] matrix = {{3, 0, 1, 4, 2}, {5, 6, 3, 2, 1}, {1, 2, 0, 1, 5}, {4, 1, 0, 1, 7}, {1, 0, 3, 0, 5}};
        NumMatrix numMatrix = new NumMatrix(matrix);
        int res = numMatrix.sumRegion(2, 1, 4, 3); // return 8 (i.e sum of the red rectangle)
        System.out.println(res);
        res = numMatrix.sumRegion(1, 1, 2, 2); // return 11 (i.e sum of the green rectangle)
        System.out.println(res);
        res = numMatrix.sumRegion(1, 2, 2, 4); // return 12 (i.e sum of the blue rectangle)
        System.out.println(res);
    }
}
