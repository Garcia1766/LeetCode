#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<int, int> map1;
        for (int i = 0; i < C.size(); i++)
            for (int j = 0; j < D.size(); j++)
                map1[C[i] + D[j]]++;
        int ans = 0;
        for (int i = 0; i < A.size(); i++)
            for (int j = 0; j < B.size(); j++)
                if (map1.find( - A[i] - B[j]) != map1.end())
                    ans += map1[ - A[i] - B[j]];
        return ans;
    }
};

int main() {
    int a[] = {1, 2}, b[] ={-2,-1}, c[] = {-1, 2}, d[] = {0, 2};
    vector<int> A(a, a + sizeof(a)/sizeof(int)), B(b, b + sizeof(b)/sizeof(int)), C(c, c + sizeof(c)/sizeof(int)), D(d, d + sizeof(d)/sizeof(int));
    cout << Solution().fourSumCount(A, B, C, D) << endl;

    return 0;
}