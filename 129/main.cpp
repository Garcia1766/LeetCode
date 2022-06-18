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
    int sumNumbers(TreeNode* root) {
        vector<vector<int>> paths = getPaths(root);
        int ret = 0;
        for (auto v : paths) {
            int tmp = 0;
            for (auto i : v) {
                tmp = tmp * 10 + i;
            }
            ret += tmp;
        }
        return ret;
    }
    vector<vector<int>> getPaths(TreeNode* root) {
        vector<vector<int>> res;
        if (!root) return res;
        if (!root->left && !root->right)
            res.push_back({root->val});
        vector<vector<int>> lres = getPaths(root->left);
        for (auto v : lres) {
            v.emplace(v.begin(), root->val);
            res.push_back(v);
        }
        vector<vector<int>> rres = getPaths(root->right);
        for (auto v : rres) {
            v.emplace(v.begin(), root->val);
            res.push_back(v);
        }
        return res;
    }
};

int main() {
    TreeNode *root = new TreeNode(3, new TreeNode(9), new TreeNode(20, new TreeNode(15), new TreeNode(7)));
    TreeNode *root2 = new TreeNode();
    TreeNode *root3 = NULL;
    TreeNode *root4 = new TreeNode(4, new TreeNode(9, new TreeNode(5), new TreeNode(1)), new TreeNode(0));
    int res = Solution().sumNumbers(root4);
    printf("%d\n", res);
    return 0;
}