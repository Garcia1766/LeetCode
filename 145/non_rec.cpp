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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        if(!root) return res;
        stack<TreeNode*> stk;
        stk.push(root);
        TreeNode *t = root;
        while (!stk.empty()) {
            if (stk.top()->right != t && stk.top()->left != t)  // 栈顶结点不是当前已访问完的节点(t)的父，则必为其右兄
                gotoHLVFL(stk);  // 以栈顶结点为根，将左侧链上所有点和其右兄入栈
            t = stk.top();  // 更新t为栈顶结点，并访问之
            stk.pop();
            res.push_back(t->val);
        }
        return res;
    }
    void gotoHLVFL(stack<TreeNode*> &stk) {  // 将左侧链上所有点和其右兄入栈
        while (stk.top()->left || stk.top()->right) {
            TreeNode *t = stk.top();
            if (t->right) stk.push(t->right);
            if (t->left) stk.push(t->left);
        }
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