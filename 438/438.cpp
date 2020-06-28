#include<iostream>
#include<cmath>
#include<algorithm>
#include<string>
#include<vector>

using namespace std;

bool zero(int arr[]) {
    return !(arr[0] || arr[1] || arr[2] || arr[3] || arr[4] || arr[5] || arr[6] || arr[7] || arr[8] || arr[9] || 
    arr[10] || arr[11] || arr[12] || arr[13] || arr[14] || arr[15] || arr[16] || arr[17] || arr[18] || arr[19] || 
    arr[20] || arr[21] || arr[22] || arr[23] || arr[24] || arr[25]);
}

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if (p.size() > s.size())
            return vector<int>();
        
        int freq[26] = {0};
        for (int i = 0; i < p.size(); i++)
            freq[p[i] - 'a']++;
        
        for (int i = 0; i < p.size(); i++)
            freq[s[i] - 'a']--;
        
        int l = 0, r = p.size() - 1;
        vector<int> ans;
        while (r + 1 < s.size()) {
            if (zero(freq)) ans.push_back(l);
            freq[s[++r] - 'a']--;
            freq[s[l++] - 'a']++;
        }
        if (zero(freq)) ans.push_back(l);

        return ans;
    }
};

int main() {
    string s = "abab", p = "ab";
    vector<int> vec = Solution().findAnagrams(s, p);
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
    }
    cout << endl;

    return 0;
}