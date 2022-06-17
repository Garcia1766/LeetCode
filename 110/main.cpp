#include<iostream>
#include<vector>
#include<queue>
#include<cmath>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void print_tree(TreeNode* root) {
    if (!root) return;
    queue<TreeNode*> q({root});
    while(!q.empty()) {
        TreeNode *cur = q.front();
        q.pop();
        printf("%d ", cur->val);
        if (cur->left) q.push(cur->left);
        if (cur->right) q.push(cur->right);
    }
    printf("\n");
}

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if (!root) return true;
        // if (root->left && !root->right && (root->left->left || root->left->right)
        //     || !root->left && root->right && (root->right->left || root->right->right))
        //     return false;
        if (abs(getHeight(root->left) - getHeight(root->right)) > 1) return false;
        return isBalanced(root->left) && isBalanced(root->right);
    }
    int getHeight(TreeNode* root) {
        if (!root) return 0;
        return 1 + max(getHeight(root->left), getHeight(root->right));
    }
};

int main() {
    TreeNode *root = new TreeNode(1, new TreeNode(2, new TreeNode(3), new TreeNode(4)),
        new TreeNode(2, new TreeNode(4), new TreeNode(3)));
    // TreeNode *root2 = new TreeNode();
    // TreeNode *root3 = NULL;
    // TreeNode *p = new TreeNode(1, new TreeNode(2), new TreeNode(3));
    // TreeNode *q = new TreeNode(1, new TreeNode(2), new TreeNode(3));
    bool res = Solution().isBalanced(root);
    printf("%d\n", res);
    return 0;
}