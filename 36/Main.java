class Solution {
    public boolean isValidSudoku(char[][] board) {
        boolean[] occur = new boolean[9];
        for (int i = 0; i < board.length; ++i) {
            for (int j = 0; j < board[0].length; ++j) {
                if (board[i][j] != '.') {
                    if (occur[board[i][j] - '1']) return false;
                    else occur[board[i][j] - '1'] = true;
                }
            }
            occur = new boolean[9];
        }
        for (int j = 0; j < board[0].length; ++j) {
            for (int i = 0; i < board.length; ++i) {
                if (board[i][j] != '.') {
                    if (occur[board[i][j] - '1']) return false;
                    else occur[board[i][j] - '1'] = true;
                }
            }
            occur = new boolean[9];
        }

        int[][] Delta = {{0,0},{0,3},{0,6},{3,0},{3,3},{3,6},{6,0},{6,3},{6,6}};
        int[][] dt = {{0,0},{0,1},{0,2},{1,0},{1,1},{1,2},{2,0},{2,1},{2,2}};
        int x, y;
        for (int i = 0; i < Delta.length; ++i) {
            for (int j = 0; j < dt.length; ++j) {
                x = Delta[i][0] + dt[j][0];
                y = Delta[i][1] + dt[j][1];
                if (board[x][y] != '.') {
                    if (occur[board[x][y] - '1']) return false;
                    else occur[board[x][y] - '1'] = true;
                }
            }
            occur = new boolean[9];
        }
        return true;
    }
}

public class Main {
    public static void main(String[] args) {
        char[][] board = {
            {'5','3','.','.','7','.','.','.','.'},
            {'6','.','.','1','9','5','.','.','.'},
            {'.','9','8','.','.','.','.','6','.'},
            {'8','.','.','.','6','.','.','.','3'},
            {'4','.','.','8','.','3','.','.','1'},
            {'7','.','.','.','2','.','.','.','6'},
            {'.','6','.','.','.','.','2','8','.'},
            {'.','.','.','4','1','9','.','.','5'},
            {'.','.','.','.','8','.','.','7','9'},
        };
        boolean res = new Solution().isValidSudoku(board);
        System.out.println(res);
    }
}
