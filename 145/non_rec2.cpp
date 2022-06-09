#include<iostream>
#include<vector>
#include<stack>
#include<cassert>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

struct Command {
    string s;
    TreeNode *t;
    Command(string s, TreeNode *t): s(s), t(t) {}
};

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        if (!root) return res;
        stack<Command> stk;
        stk.push(Command("go", root));
        while (!stk.empty()) {
            Command cmd = stk.top();
            stk.pop();
            if (cmd.s == "go") {
                stk.push(Command("visit", cmd.t));
                if (cmd.t->right) stk.push(Command("go", cmd.t->right));
                if (cmd.t->left) stk.push(Command("go", cmd.t->left));
            } else {
                assert(cmd.s == "visit");
                res.push_back(cmd.t->val);
            }
        }
        return res;
    }
};

int main() {
    TreeNode root(1, NULL, new TreeNode(2, new TreeNode(3), NULL));
    vector<int> res = Solution().postorderTraversal(&root);
    for (int i = 0; i < res.size(); i++) {
        printf("%d ", res[i]);
    } printf("\n");
    return 0;
}