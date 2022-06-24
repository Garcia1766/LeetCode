#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<cassert>

using namespace std;

class Solution {
private:
    bool check_valid(string s) {
        int trans = atoi(s.c_str());
        if (trans <= 255 && to_string(trans) == s) return true;
        return false;
    }
    vector<string> res;
    void findAddress(const string& s, int idx, string stored, int cnt) {
        if (cnt > 4) return;  // 这样写比在cnt==4时用return要快很多(8ms vs 34ms)
        if (cnt == 4 && idx == s.size()) {
            res.push_back(stored);
            // return;
        }
        for (int i = 1; i <= 3 && idx + i <= s.size(); i++) {
            string tmp = s.substr(idx, i);
            if (check_valid(tmp)) {
                findAddress(s, idx + i, stored + tmp + (cnt == 3 ? "" : "."), cnt + 1);
            }
        }
    }
public:
    vector<string> restoreIpAddresses(string s) {
        findAddress(s, 0, "", 0);
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