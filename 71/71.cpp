#include<iostream>
#include<string>
#include<stack>
#include<vector>

using namespace std;

class Solution {
public:
    void print_stack(stack<char> stk) {
        while (!stk.empty()) {
            printf("%c", stk.top());
            stk.pop();
        }
        printf("\n");
    }

    string simplifyPath(string path) {
        if (path.size() == 1) return path;
        stack<char> stk;
        stk.push(path[0]);
        for (int i = 1; i < path.size(); i++) {
            print_stack(stk);
            printf("Current char: %c\n", path[i]);
            if (stk.top() == '/') {
                if (path[i] == '/') continue;  // "/"
                else if (path[i] == '.' && i <= path.size() - 2 && path[i + 1] == '/') {  // "./"
                    i++;
                    continue;
                } else if (path[i] == '.' && i == path.size() - 1) break;  // ".END"
                else if (path[i] == '.' && i <= path.size() - 3 && path[i + 1] == '.' && path[i + 2] == '/') {  // "../"
                    if (stk.size() > 1) {  // return to parent dir
                        stk.pop();
                        while(stk.top() != '/') stk.pop();
                    }
                    i += 2;
                    continue;
                } else if (path[i] == '.' && i == path.size() - 2 && path[i + 1] == '.') {  // "..END"
                    if (stk.size() > 1) {  // return to parent dir
                        stk.pop();
                        while(stk.top() != '/') stk.pop();
                    }
                    break;
                }
                else stk.push(path[i]);
            } else {
                if (path[i] == '/') {
                    if (i == path.size() - 1) break;
                    else stk.push(path[i]);
                } else stk.push(path[i]);
            }
        }
        if (stk.top() == '/' && stk.size() > 1) stk.pop();
        string ret(stk.size(), '\0');
        for (int i = ret.size() - 1; i >= 0; i--) {
            ret[i] = stk.top();
            stk.pop();
        }
        return ret;
    }
};

int main() {
    // vector<string> tokens {"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
    // int res = Solution().evalRPN(tokens);
    // printf("%d\n", res);
    string path = "/a//b////c/d//././/..";
    printf("Input path: %s\n", path.c_str());
    string res = Solution().simplifyPath(path);
    printf("%s\n", res.c_str());

    return 0;
}