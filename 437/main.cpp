#include<iostream>
#include<vector>
#include<queue>

#define ll long long

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
    // return the number of paths where the sum of the values along the path equals targetSum.
    // The path does not need to start or end at the root or a leaf
    int pathSum(TreeNode* root, int targetSum) {
        if (!root) return 0;
        int res = 0;
        res += pathNum(root, (ll)targetSum);
        res += pathSum(root->left, targetSum);
        res += pathSum(root->right, targetSum);
        return res;
    }

    // return the number of paths where the sum of the values along the path equals targetSum.
    // The path must start at the root, but does not need to end at a leaf
    int pathNum(TreeNode* root, ll sum) {
        if (!root) return 0;
        int res = 0;
        if (root->val == sum) res += 1;
        res += pathNum(root->left, sum - (ll)root->val);
        res += pathNum(root->right, sum - (ll)root->val);
        return res;
    }
};

int main() {
    TreeNode *root = new TreeNode(3, new TreeNode(9), new TreeNode(20, new TreeNode(15), new TreeNode(7)));
    TreeNode *root2 = new TreeNode();
    TreeNode *root3 = NULL;
    TreeNode *root4 = new TreeNode(4, new TreeNode(9, new TreeNode(5), new TreeNode(1)), new TreeNode(0));
    int res = Solution().pathSum(root4, 8);
    printf("%d\n", res);
    ll a = 3;
    int b = 3;
    printf("%d\n", a==b);  // True
    return 0;
}