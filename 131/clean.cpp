#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<cassert>

using namespace std;

void print_vector(vector<string> vec, bool newline){
    printf("[");
    for (int i = 0; i < vec.size(); i++)
        printf("%s,", vec[i].c_str());
    printf("]");
    if (newline) printf("\n");
}

class Solution {
private:
    vector<vector<string>> res;
    bool check_palindrome(string s) {
        for (int i = 0; i <= (s.size() >> 1); i++)
            if (s[i] != s[s.size() - 1 - i])
                return false;
        return true;
    }
    void findPalindrome(const string& s, int idx, vector<string> stored) {
        if (idx >= s.size()) {
            res.push_back(stored);
            return;
        }

        for (int i = 1; idx + i <= s.size(); i++) {
            string sub = s.substr(idx, i);
            if (check_palindrome(sub)) {
                stored.push_back(sub);
                findPalindrome(s, idx + i, stored);
                stored.pop_back();
            }
        }
        return;
    }
public:
    vector<vector<string>> partition(string s) {
        vector<string> stored;
        findPalindrome(s, 0, stored);
        return res;
    }
};

int main() {
    string digits = "abab";
    vector<vector<string>> res = Solution().partition(digits);
    for (int i = 0; i < res.size(); i++) {
        print_vector(res[i], false);
        printf(", ");
    } printf("\n");
    return 0;
}