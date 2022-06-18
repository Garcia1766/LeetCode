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
    int minDepth(TreeNode* root) {
        if (!root) return 0;
        if (!root->left && !root->right) return 1;
        if (root->left && !root->right) return minDepth(root->left) + 1;
        if (!root->left && root->right) return minDepth(root->right) + 1;
        return (min(minDepth(root->left), minDepth(root->right)) + 1);
    }
};

class Solution1 {
public:
    // 这样写不对，不能像112题一样简化，因为本题定义空树的minDepth是0
    int minDepth(TreeNode* root) {
        if (!root) return INT32_MAX;
        if (!root->left && !root->right) return 1;
        // if (root->left && !root->right) return minDepth(root->left) + 1;
        // if (!root->left && root->right) return minDepth(root->right) + 1;
        return (min(minDepth(root->left), minDepth(root->right)) + 1);
    }
};

int main() {
    TreeNode *root = new TreeNode(3, new TreeNode(9), new TreeNode(20, new TreeNode(15), new TreeNode(7)));
    TreeNode *root2 = new TreeNode();
    TreeNode *root3 = NULL;
    int res = Solution().minDepth(root);
    printf("%d\n", res);
    return 0;
}