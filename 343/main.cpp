#include<iostream>
#include<vector>
#include<cassert>

using namespace std;

class Solution {
private:
    int max3(int a, int b, int c) {
        return max(a, max(b, c));
    }
public:
    int integerBreak(int n) {
        assert(n >= 2);
        vector<int> res(n + 1, -1);
        res[1] = 1;
        for (int i = 2; i <= n; i++) {
            // Calculate res[i] by splitting i to j + (i - j)
            for (int j = 1; j < i; j++) {
                res[i] = max3(res[i], j * (i - j), j * res[i - j]);
            }
        }
        return res[n];
    }
};

int main() {
    int n = 10;
    int res = Solution().integerBreak(n);
    printf("%d\n", res);
    return 0;
}
