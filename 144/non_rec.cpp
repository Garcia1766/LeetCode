#include<iostream>
#include<vector>
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

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if (!root) return res;
        stack<TreeNode*> stk;
        while (true) {
            visitAlongVine(root, stk, res);  // 访问左侧链上所有点，将右侧所有子树入栈
            if (stk.empty()) break;  // 若栈空则结束
            root = stk.top();  // 否则开始访问右侧子树中最下面的一棵
            stk.pop();
        }
        return res;
    }
    static void visitAlongVine(TreeNode *t, stack<TreeNode*>& stk, vector<int>& res) {
        // 访问左侧链上所有点，将右侧所有子树入栈
        while (t) {
            res.push_back(t->val);  // visit
            if (t->right) stk.push(t->right);
            t = t->left;
        }
    }
};

int main() {
    TreeNode root(1, NULL, new TreeNode(2, new TreeNode(3), NULL));
    vector<int> res = Solution().preorderTraversal(&root);
    for (int i = 0; i < res.size(); i++) {
        printf("%d ", res[i]);
    } printf("\n");
    return 0;
}