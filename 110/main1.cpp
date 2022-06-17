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
        return getHeight(root) != -1;
    }
    int getHeight(TreeNode* root) {
        if (!root) return 0;
        int lh = getHeight(root->left);
        if (lh == -1) return -1;
        int rh = getHeight(root->right);
        if (rh == -1) return -1;
        if (abs(lh - rh) > 1) return -1;
        return 1 + max(lh, rh);
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