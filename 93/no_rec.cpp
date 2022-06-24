#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<cassert>

using namespace std;

class Solution {
private:
    vector<string> res;
public:
    vector<string> restoreIpAddresses(string s) {
        for (int a = 1; a <= 3; a++)
        for (int b = 1; b <= 3; b++)
        for (int c = 1; c <= 3; c++)
        for (int d = 1; d <= 3; d++)
            if (a+b+c+d == s.size()) {
                int A = atoi(s.substr(0, a).c_str());
                int B = atoi(s.substr(a, b).c_str());
                int C = atoi(s.substr(a+b, c).c_str());
                int D = atoi(s.substr(a+b+c, d).c_str());
                if (A<=255 && B<=255 && C<=255 && D<=255) {
                    string ans = to_string(A) + "." + to_string(B) + "." + to_string(C) + "." + to_string(D);
                    if (ans.size() == s.size() + 3)
                        res.push_back(ans);
                }
            }
        return res;
    }
};

int main() {
    string digits = "25525511135";
    vector<string> res = Solution().restoreIpAddresses(digits);
    for (auto s : res) cout << s << " ";
    cout << endl;
    return 0;
}