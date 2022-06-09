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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        if(!root) return res;
        stack<TreeNode*> stk;
        while (true) {
            goAlongVine(root, stk, res);  // 将左侧链上所有点入栈
            if (stk.empty()) break;  // 若栈空则结束
            TreeNode *t = stk.top();
            stk.pop();
            res.push_back(t->val);  // visit
            root = t->right;  // 否则开始访问右侧子树中最下面的一棵
        }
        return res;
    }
    void goAlongVine(TreeNode *t, stack<TreeNode*>& stk, vector<int>& res) {
        // 将左侧链上所有点入栈
        while(t) {
            stk.push(t);
            t = t->left;
        }
    }
};

int main() {
    TreeNode root(1, NULL, new TreeNode(2, new TreeNode(3), NULL));
    vector<int> res = Solution().inorderTraversal(&root);
    for (int i = 0; i < res.size(); i++) {
        printf("%d ", res[i]);
    } printf("\n");
    return 0;
}