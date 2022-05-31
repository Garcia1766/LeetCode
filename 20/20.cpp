#include<iostream>
#include<string>
#include<stack>
#include<vector>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') stk.push(s[i]);
            else {
                if (stk.empty()) return false;
                char cur = stk.top();
                stk.pop();
                char tar = '0';
                switch (s[i])
                {
                case ')':
                    tar = '(';
                    break;
                case ']':
                    tar = '[';
                    break;
                case '}':
                    tar = '{';
                    break;
                default:
                    break;
                }
                if (cur != tar) return false;
            }
        }
        if (!stk.empty()) return false;
        return true;
    }
};

int main() {
    string s = "()[]{}";
    printf("%d\n", Solution().isValid(s));

    return 0;
}