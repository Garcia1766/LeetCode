#include<iostream>
#include<cmath>
#include<vector>
#include<set>

using namespace std;

int SquareSum (int n) {
    int ans = 0;
    while (n > 0) {
        ans += (n % 10) * (n % 10);
        n /= 10;
    }
    return ans;
}

class Solution {
public:
    bool isHappy(int n) {
        set<int> set1;
        set1.insert(n);
        int s_n = SquareSum(n);
        while (s_n != 1 && set1.find(s_n) == set1.end()) {
            set1.insert(s_n);
            n = s_n;
            s_n = SquareSum(n);
        }
        if (s_n == 1)
            return true;
        else
            return false;
    }
};

int main() {
    int n = 19;
    cout << Solution().isHappy(n) << endl;

    return 0;
}