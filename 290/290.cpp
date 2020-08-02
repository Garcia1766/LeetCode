#include<iostream>
#include<cmath>
#include<string>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string str) {
        vector<string> vecstr;
        for (int i = 0, j = 0; i < str.length(); i++) {
            if (str[i] == ' ') {
                vecstr.push_back(str.substr(j, i - j));
                j = i + 1;
            }
            if (i == str.length() - 1)
                vecstr.push_back(str.substr(j, i - j + 1));
        }
        if (pattern.size() != vecstr.size())
            return false;

        unordered_map<char, string> map1;
        unordered_map<string, char> map2;
        for (int i = 0; i < pattern.size(); i++) {
            if (map1.find(pattern[i]) == map1.end())  // not found
                map1.insert(make_pair(pattern[i], vecstr[i]));
            else
                if (map1[pattern[i]] != vecstr[i])
                    return false;
            if (map2.find(vecstr[i]) == map2.end())  // not found
                map2.insert(make_pair(vecstr[i], pattern[i]));
            else
                if (map2[vecstr[i]] != pattern[i])
                    return false;
        }
        return true;
    }
};

int main() {
    string pattern = "abba", str = "dog cat cat dog";
    cout << Solution().wordPattern(pattern, str) << endl;

    return 0;
}