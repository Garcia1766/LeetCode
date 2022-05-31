#include<iostream>
#include<string>
#include<stack>
#include<vector>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        for (int i = 0; i < tokens.size(); i++) {
            if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/") {
                int a1 = stk.top(); stk.pop();
                int a2 = stk.top(); stk.pop();
                switch (tokens[i][0])
                {
                case '+':
                    stk.push(a1 + a2);
                    break;
                case '-':
                    stk.push(a2 - a1);
                    break;
                case '*':
                    stk.push(a1 * a2);
                    break;
                case '/':
                    stk.push(a2 / a1);
                    break;
                default:
                    break;
                }
            } else {
                stk.push(stoi(tokens[i]));
            }
        }
        return stk.top();
    }
};

int main() {
    vector<string> tokens {"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
    int res = Solution().evalRPN(tokens);
    printf("%d\n", res);

    return 0;
}