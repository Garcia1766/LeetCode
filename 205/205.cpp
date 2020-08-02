#include<iostream>
#include<string>
#include<unordered_map>

using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> map1;
        unordered_map<char, char> map2;
        for (int i = 0; i < s.size(); i++) {
            if (map1.find(s[i]) == map1.end()) {  // not found
                map1.insert(make_pair(s[i], t[i]));
            }
            else
                if (map1[s[i]] != t[i])
                    return false;
            if (map2.find(t[i]) == map2.end()) {  // not found
                map2.insert(make_pair(t[i], s[i]));
            }
            else
                if (map2[t[i]] != s[i])
                    return false;
        }
        return true;
    }
};

int main() {
    string s = "title", t = "paper";
    cout << Solution().isIsomorphic(s, t) << endl;

    return 0;
}
