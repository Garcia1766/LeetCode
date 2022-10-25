#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        vector<int> sol(n + 1);
        sol[0] = 1;
        sol[1] = 1;
        for (int i = 2; i <= n; i++) {
            sol[i] = sol[i - 1] + sol[i - 2];
        }
        return sol[n];
    }
};

int main() {
    int n = 3;
    int res = Solution().climbStairs(n);
    printf("%d\n", res);
    return 0;
}
