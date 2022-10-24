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
    vector<vector<bool>> visited;
    queue<pair<int,int>> que;
    vector<pair<int,int>> vec;
    vector<pair<int,int>> delta = {{0,1},{-1,0},{0,-1},{1,0}};

    bool inBoard(int x, int y) {
        return 0 <= x && x < M && 0 <= y && y < N;
    }

    bool bfs(const vector<vector<char>>& board, int x, int y) {
        // assert(board[x][y] == 'O' && !visited[x][y]);
        bool surrounded = true;
        que.push({x, y});
        visited[x][y] = true;
        vec.push_back({x, y});
        while (!que.empty()) {
            pair<int,int> coor = que.front();
            que.pop();
            for (auto dt : delta) {
                int nx = coor.first + dt.first;
                int ny = coor.second + dt.second;
                if (inBoard(nx, ny)) {
                    if (board[nx][ny] == 'O' && !visited[nx][ny]) {
                        que.push({nx, ny});
                        visited[nx][ny] = true;
                        vec.push_back({nx, ny});
                    }
                } else {
                    surrounded = false;
                }
            }
        }
        return surrounded;
    }
public:
    void solve(vector<vector<char>>& board) {
        M = board.size();
        assert(M > 0);
        N = board[0].size();
        visited = vector<vector<bool>>(M, vector<bool>(N, false));

        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                if (board[i][j] == 'O' && !visited[i][j]) {
                    bool ret = bfs(board, i, j);
                    if (ret) {
                        for (auto v : vec) {
                            board[v.first][v.second] = 'X';
                        }
                    }
                    que = queue<pair<int,int>>();
                    vec.clear();
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
