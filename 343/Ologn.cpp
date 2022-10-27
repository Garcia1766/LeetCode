/***
 * O(log n) solution.
 * Same as O(n) solution's analysis, every integer can be considered as the form of 3k, 3k+1, or 3k+2.
 * ***/
#include<iostream>
#include<vector>
#include<cassert>
#include<cmath>

using namespace std;

class Solution {
public:
    int integerBreak(int n) {
        if (n == 2) return 1;
        if (n == 3) return 2;
        int res = 1;
        switch (n % 3)
        {
        case 0:
            res = (int)pow(3, n/3);
            break;
        case 1:
            res = (int)pow(3, n/3 - 1) * 4;
            break;
        case 2:
            res = (int)pow(3, n/3) * 2;
            break;
        default:
            break;
        }
        return res;
    }
};

int main() {
    int n = 10;
    int res = Solution().integerBreak(n);
    printf("%d\n", res);
    return 0;
}
