#include<iostream>
#include<vector>

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
        if (root) {
            vector<int> v1 = postorderTraversal(root->left);
            res.insert(res.end(), v1.begin(), v1.end());
            vector<int> v2 = postorderTraversal(root->right);
            res.insert(res.end(), v2.begin(), v2.end());
            res.push_back(root->val);
        }
        return res;
    }
};