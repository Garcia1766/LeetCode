#include<iostream>
#include<queue>
#include<vector>

using namespace std;

class Solution {
public:
    int numSquares(int n) {
        queue<pair<int, int>> que;  // <node, distance>
        vector<bool> visited(n + 1, false);

        que.push(make_pair(n, 0));
        visited[n] = true;
        while (!que.empty()) {
            int nd = que.front().first;
            int dis = que.front().second;
            que.pop();
            if (nd == 0) return dis;
            for (int i = 1; ; i++) {
                int a = nd - i*i;
                if (a < 0) break;
                if (!visited[a]) {
                    que.push(make_pair(a, dis + 1));
                    visited[a] = true;
                }
            }
        }

        throw invalid_argument("No Solution");
    }
};

int main() {
    int n = 13;
    int res = Solution().numSquares(n);
    printf("%d\n", res);
    return 0;
}