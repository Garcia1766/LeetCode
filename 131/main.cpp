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
        printf("idx = %d, explored = \"%s\", stored = ", idx, s.substr(0, idx).c_str());
        print_vector(stored, true);

        if (idx >= s.size()) {
            res.push_back(stored);
            printf("find one partition: ");
            print_vector(stored, true);
            return;
        }

        for (int i = 1; idx + i <= s.size(); i++) {
            string sub = s.substr(idx, i);
            printf("checking [%d,%d)=\"%s\"\n", idx, idx + i, sub.c_str());
            if (check_palindrome(sub)) {
                stored.push_back(sub);
                findPalindrome(s, idx + i, stored);
                stored.pop_back();  // 此for循环意为探索idx之后的串，所以stored中只能存idx及之前的串
            }
        }

        printf("idx = %d, explored = \"%s\" completed, stored = ", idx, s.substr(0, idx).c_str());
        print_vector(stored, true);
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