/***
 * O(n) solution.
 * Since (N/2)*(N/2)>=N => N>=4, (N+1)/2 * (N-1)/2 >= N => N>=5, N should be split to 2 and 3 whenever N>=4. And 4 should be split to 2*2.
 * Since 3*3 > 2*2*2, every number >=6 should use 3 as many as possible.
 * ***/
#include<iostream>
#include<vector>
#include<cassert>

using namespace std;

class Solution {
public:
    int integerBreak(int n) {
        if (n == 2) return 1;
        if (n == 3) return 2;
        int res = 1;
        while (n >= 5) {
            res *= 3;
            n -= 3;
        }
        res *= n;
        return res;
    }
};

int main() {
    int n = 10;
    int res = Solution().integerBreak(n);
    printf("%d\n", res);
    return 0;
}
