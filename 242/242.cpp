#include<iostream>
#include<ctime>
#include<cassert>
#include<cmath>
#include<string>
#include<unordered_map>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length())
            return false;
        
        unordered_map<char, int> map1;
        for (int i = 0; i < s.length(); i++) {
            map1[s[i]]++;
        }
        int unbalance = s.length();

        for (int i = 0; i < t.length(); i++) {
            if (map1[t[i]] > 0) {
                map1[t[i]]--;
                unbalance--;
            }
        }
        return !unbalance;
    }
};

int main() {
    string s = "rat", t = "car";
    cout << Solution().isAnagram(s, t) << endl;

    return 0;
}