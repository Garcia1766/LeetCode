#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<cassert>
#include<unordered_map>
#include<algorithm>

using namespace std;

void print_vector(vector<int> vec, bool newline = true){
    printf("[");
    for (int i = 0; i < vec.size(); i++)
        printf("%d,", vec[i]);
    printf("]");
    if (newline) printf("\n");
}

void print_mat(vector<vector<char>> mat) {
    for (auto a : mat) {
        for (auto b : a) {
            printf("%c ", b);
        }
        printf("\n");
    }
}

class Solution {
private:
    vector<vector<int>> delta = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}};
    int M, N;
    bool inBoard(int x, int y) {
        return 0 <= x && x < M && 0 <= y && y < N;
    }
    vector<vector<bool>> visited;

    bool searchWord(const vector<vector<char>>& board, const string& word, int idx, int x, int y) {
        // printf("Searching %s from (%d,%d), %c\n", word.substr(idx).c_str(), x, y, board[x][y]);
        if (idx == word.size() - 1) 
            return board[x][y] == word[idx];

        if (board[x][y] != word[idx])
            return false;
        
        // board[x][y] == word[idx], search next position
        visited[x][y] = true;
        for (int i = 0; i < delta.size(); i++) {
            int nx = x + delta[i][0];
            int ny = y + delta[i][1];
            if (inBoard(nx, ny) && !visited[nx][ny]) {
                if (searchWord(board, word, idx + 1, nx, ny))
                    return true;
            }
        }
        visited[x][y] = false;
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        M = board.size();
        assert(M > 0);
        N = board[0].size();
        visited = vector<vector<bool>>(M, vector<bool>(N, false));

        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                if (searchWord(board, word, 0, i, j)) {
                    return true;
                }
            }
        }
        return false;
    }
};

int main() {
    vector<vector<char>> board = {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
    string word = "ABCB";
    bool res = Solution().exist(board, word);
    printf("%d\n", res);
    return 0;
}
