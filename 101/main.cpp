#include<iostream>
#include<vector>
#include<queue>

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

// refer to Prob 226 and 100
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (!root->left && root->right || root->left && !root->right) return false;
        return isSameSym(root->left, root->right);
    }
    bool isSameSym(TreeNode *p, TreeNode *q) {
        if (!p && !q) return true;
        if (!p && q || p && !q || (p && q && p->val != q->val)) return false;
        return (isSameSym(p->left, q->right) && isSameSym(p->right, q->left));
    }
};

int main() {
    TreeNode *root = new TreeNode(1, new TreeNode(2, new TreeNode(3), new TreeNode(4)),
        new TreeNode(2, new TreeNode(4), new TreeNode(3)));
    // TreeNode *root2 = new TreeNode();
    // TreeNode *root3 = NULL;
    // TreeNode *p = new TreeNode(1, new TreeNode(2), new TreeNode(3));
    // TreeNode *q = new TreeNode(1, new TreeNode(2), new TreeNode(3));
    bool res = Solution().isSymmetric(root);
    printf("%d\n", res);
    return 0;
}