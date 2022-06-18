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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        if (!root) return res;
        if (!root->left && !root->right) {
            res.push_back(to_string(root->val));
            return res;
        }
        vector<string> lps = binaryTreePaths(root->left);
        for (auto s : lps) {
            res.push_back(to_string(root->val) + "->" + s);
        }
        vector<string> rps = binaryTreePaths(root->right);
        for (auto s : rps) {
            res.push_back(to_string(root->val) + "->" + s);
        }
        return res;
    }
};

int main() {
    TreeNode *root = new TreeNode(3, new TreeNode(9), new TreeNode(20, new TreeNode(15), new TreeNode(7)));
    TreeNode *root2 = new TreeNode();
    TreeNode *root3 = NULL;
    vector<string> res = Solution().binaryTreePaths(root);
    for (auto s : res)
        printf("%s\n", s.c_str());
    return 0;
}