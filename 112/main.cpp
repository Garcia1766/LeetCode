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

class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root) return false;
        if (!root->left && !root->right) return targetSum == root->val;
        // if (!root->left && root->right) return hasPathSum(root->right, targetSum - root->val);
        // if (root->left && !root->right) return hasPathSum(root->left, targetSum - root->val);
        return hasPathSum(root->left, targetSum - root->val) || hasPathSum(root->right, targetSum - root->val); // if (root->left && root->right)
    }
};

int main() {
    TreeNode *root = new TreeNode(3, new TreeNode(9), new TreeNode(20, new TreeNode(15), new TreeNode(7)));
    TreeNode *root2 = new TreeNode();
    TreeNode *root3 = NULL;
    int res = Solution().hasPathSum(root, 12);
    printf("%d\n", res);
    return 0;
}