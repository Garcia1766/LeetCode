#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<cassert>

using namespace std;

class Solution {
private:
    const string letterMap[10] = {
        "",
        "",
        "abc",
        "def",
        "ghi",
        "jkl",
        "mno",
        "pqrs",
        "tuv",
        "wxyz"
    };
    vector<string> res;
    void findCombination(const string& digits, int ind, const string& s) {
        if (s.size() == digits.size()) {
            res.push_back(s);
            return;
        }
        char c = digits[ind];
        assert(c >= '2' && c <= '9');
        string letters = letterMap[c - '0'];
        for (int i = 0; i < letters.size(); i++)
            findCombination(digits, ind + 1, s + letters[i]);
        return;
    }
public:
    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0) return res;
        findCombination(digits, 0, "");
        return res;
    }
};

int main() {
    string digits = "23";
    vector<string> res = Solution().letterCombinations(digits);
    for (auto s : res) cout << s << " ";
    cout << endl;
    return 0;
}