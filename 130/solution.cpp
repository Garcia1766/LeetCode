#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<cassert>
#include<unordered_map>
#include<algorithm>

using namespace std;

template<typename T>
void print_vector(vector<T> vec, bool newline = true){
    printf("[");
    for (int i = 0; i < vec.size(); i++) {
        printf("%d,", vec[i]);
    }
    printf("]");
    if (newline) printf("\n");
}

template<typename T>
void print_mat(vector<vector<T>> mat) {
    for (auto a : mat) {
        for (auto b : a) {
            printf("%c ", b);
        }
        printf("\n");
    }
}

class Solution {
private:
    int M, N;
    queue<pair<int,int>> que;
    vector<pair<int,int>> delta = {{0,1},{-1,0},{0,-1},{1,0}};

    bool inBoard(int x, int y) {
        return 0 <= x && x < M && 0 <= y && y < N;
    }

    void bfs(vector<vector<char>>& board, int x, int y) {
        // assert(board[x][y] == 'O');
        que.push({x, y});
        board[x][y] = 'E';
        while (!que.empty()) {
            pair<int,int> coor = que.front();
            que.pop();
            for (auto dt : delta) {
                int nx = coor.first + dt.first;
                int ny = coor.second + dt.second;
                if (inBoard(nx, ny) && board[nx][ny] == 'O') {
                    que.push({nx, ny});
                    board[nx][ny] = 'E';
                }
            }
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        M = board.size();
        assert(M > 0);
        N = board[0].size();
        vector<pair<int,int>> border;
        for (int i = 0; i < M; i++)
            border.push_back({i, 0});
        if (N > 1)
            for (int i = 0; i < M; i++)
                border.push_back({i, N-1});
        
        for (int j = 1; j < N - 1; j++)
            border.push_back({0, j});
        if (M > 1)
            for (int j = 1; j < N - 1; j++)
                border.push_back({M-1, j});

        for (auto coor : border) {
            if (board[coor.first][coor.second] == 'O') {
                bfs(board, coor.first, coor.second);
            }
        }

        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                if (board[i][j] == 'E') {
                    board[i][j] = 'O';
                } else if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
    }
};

int main() {
    vector<vector<char>> board = {
        {'X','X','X','X'},
        {'X','O','O','X'},
        {'X','X','O','X'},
        {'X','O','X','X'}};
    vector<vector<char>> board1 = {
        {'O','O','O','O','O','O'},
        {'O','X','X','X','X','O'},
        {'O','X','O','O','X','O'},
        {'O','X','O','O','X','O'},
        {'O','X','X','X','X','O'},
        {'O','O','O','O','O','O'}};
    vector<vector<char>> board2 = {
        {'X','O','O','X','X','X','O','X','O','O'},
        {'X','O','X','X','X','X','X','X','X','X'},
        {'X','X','X','X','O','X','X','X','X','X'},
        {'X','O','X','X','X','O','X','X','X','O'},
        {'O','X','X','X','O','X','O','X','O','X'},
        {'X','X','O','X','X','O','O','X','X','X'},
        {'O','X','X','O','O','X','O','X','X','O'},
        {'O','X','X','X','X','X','O','X','X','X'},
        {'X','O','O','X','X','O','X','X','O','O'},
        {'X','X','X','O','O','X','O','X','X','O'}};
    print_mat(board2);
    printf("-------------------\n");
    Solution().solve(board2);
    print_mat(board2);
    return 0;
}
