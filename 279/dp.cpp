#include<iostream>
#include<vector>

using namespace std;

void print_vec(vector<int>& vec) {
    for (auto i : vec) {
        printf("%d ", i);
    }
    printf("\n");
}

class Solution {
public:
    int numSquares(int n) {
        vector<int> res(n + 1, INT32_MAX);
        for (int i = 1; i*i <= n; i++) {
            res[i*i] = 1;
        }

        for (int i = 2; i <= n; i++) {
            if (res[i] != INT32_MAX) continue;
            for (int j = 1; j*j < i; j++) {
                res[i] = min(res[i], res[j*j] + res[i - j*j]);
            }
        }

        return res[n];
    }
};

int main() {
    int n = 13;
    int res = Solution().numSquares(n);
    printf("%d\n", res);
    return 0;
}