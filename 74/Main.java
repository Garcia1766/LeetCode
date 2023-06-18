class Solution {
    public void printMatrix(int[][] mat) {
        for (int i = 0; i < mat.length; ++i) {
            for (int j = 0; j < mat[0].length; ++j) {
                System.out.printf("%d,", mat[i][j]);
            }
            System.out.println();
        }
        System.out.println();
    }

    public boolean searchMatrix(int[][] matrix, int target) {
        int m = matrix.length, n = matrix[0].length;
        int[] coord = new int[m * n];
        for (int i = 0; i < coord.length; ++i) {
            coord[i] = i;
        }

        int l = 0, r = m * n - 1, mid = (l + r) >> 1;
        while (l <= r) {
            int x = mid / n;
            int y = mid % n;
            if (matrix[x][y] < target) {
                l = mid + 1; // 更新时不要 l=mid 而是 l=mid+1，就能减少边角情况。不是精确查找元素时，两侧中的一侧用mid，一侧用mid+1或mid-1
            } else if (matrix[x][y] > target) {
                r = mid - 1;
            } else {
                return true;
            }
            mid = (l + r) >> 1;
        }
        
        return false;
    }
}

public class Main {
    public static void main(String[] args) {
        int[][] matrix = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
        int target = 3;
        boolean res = new Solution().searchMatrix(matrix, target);
        System.out.println(res);
    }
}
