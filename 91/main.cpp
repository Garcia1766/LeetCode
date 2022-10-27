#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        vector<int> res(n, -1);
        res[0] = s[0] == '0' ? 0 : 1;
        
        for (int i = 1; i < n; i++) {
            int a, b;
            a = s[i] == '0' ? 0 : res[i - 1];
            if (s[i - 1] != '0' && stoi(s.substr(i - 1, 2)) <= 26) {
                b = i < 2 ? 1 : res[i - 2];
            } else {
                b = 0;
            }
            res[i] = a + b;
        }
        return res[n - 1];
    }
};
