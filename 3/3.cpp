#include<iostream>
#include<cmath>
#include<algorithm>
#include<string>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0, r = -1, ans = 0;
        bool freq[256] = {false};

        while (l < s.size()) {
            if ( r + 1 < s.size() && !freq[s[r + 1]])
                freq[s[++r]] = true;
            else {
                if (r + 1 == s.size()) break;
                freq[s[l++]] = false;
            }

            ans = max(ans, r-l+1);
        }
        return ans;
    }
};

int main() {
    string s = "bbbbbb";
    cout << Solution().lengthOfLongestSubstring(s) << endl;

    return 0;
}