class Solution {
    private final int[][] dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    private int m, n;

    private int dfs(int[][] matrix, int i, int j, int[][] cache) {
        if (cache[i][j] > 0) return cache[i][j];
        for (int[] d : dir) {
            int x = i + d[0], y = j + d[1];
            if (0 <= x && x < m && 0 <= y && y < n && matrix[i][j] < matrix[x][y]) {
                cache[i][j] = Math.max(cache[i][j], dfs(matrix, x, y, cache));
            }
        }
        return ++cache[i][j];
    }
    
    public int longestIncreasingPath(int[][] matrix) {
        this.m = matrix.length;
        this.n = matrix[0].length;
        int[][] cache = new int[m][n];
        int res = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                res = Math.max(res, dfs(matrix, i, j, cache));
            }
        }
        return res;
    }
}

public class DFS {
    public static void main(String[] args) {
        int[][] matrix = {{3,4,5},{3,2,6},{2,2,1}};
        int res = new Solution().longestIncreasingPath(matrix);
        System.out.println(res);
    }
}
