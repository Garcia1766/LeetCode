#include<iostream>
#include<cmath>
#include<algorithm>
#include<string>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        int freq[256] = {0}, num_neg = 0;
        for (int i = 0; i < t.size(); i++) {
            freq[t[i]]--;
            num_neg++;
        }
        int l = 0, r = -1, width = INT32_MAX;
        string ans;
        while (l < s.size()) {

            if (r + 1 < s.size() && num_neg > 0) {
                freq[s[++r]]++;
                if (freq[s[r]] <= 0)
                    num_neg--;
            } else {
                freq[s[l++]]--;
                if (freq[s[l - 1]] < 0)
                    num_neg++;
                if (r + 1 == s.size() && num_neg > 0)
                    break;
            }

            if (num_neg == 0) {
                if (r-l+1 < width) {
                    ans = s.substr(l, r-l+1);
                    width = r-l+1;
                }
            }
        }
        if (width == INT32_MAX)
            return "";
        return ans;
    }
};

int main() {
    string s = "ADOBECODEBANC", t = "ABC";
    cout << Solution().minWindow(s, t) << endl;

    return 0;
}