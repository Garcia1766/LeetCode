#include<iostream>
#include<vector>
#include<queue>
#include<stack>

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
    bool isValidBST(TreeNode* root) {
        vector<int> vec;
        stack<Command> stk;
        stk.push(Command("go", root));
        while (!stk.empty()) {
            Command cur = stk.top();
            stk.pop();
            if (cur.s == "go") {
                if (cur.t->right) stk.push(Command("go", cur.t->right));
                stk.push(Command("visit", cur.t));
                if (cur.t->left) stk.push(Command("go", cur.t->left));
            } else {  // cur.s == "visit"
                vec.push_back(cur.t->val);
            }
        }
        for (int i = 0; i < vec.size() - 1; i++) {
            if (vec[i] >= vec[i + 1]) return false;
        }
        return true;
    }
};

int main() {
    TreeNode *root = new TreeNode(3, new TreeNode(9), new TreeNode(20, new TreeNode(15), new TreeNode(7)));
    TreeNode *root2 = new TreeNode();
    TreeNode *root3 = NULL;
    TreeNode *root4 = new TreeNode(4, new TreeNode(9, new TreeNode(5), new TreeNode(1)), new TreeNode(0));
    bool res = Solution().isValidBST(root2);
    printf("%d\n", res);
    return 0;
}