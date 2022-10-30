#include<iostream>

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
    // <rob_this_node, not_rob_this_node>
    pair<int, int> getVal(TreeNode* root) {
        if (!root) return make_pair(0, 0);
        pair<int, int> lv = getVal(root->left);
        pair<int, int> rv = getVal(root->right);
        int rob = root->val + lv.second + rv.second;
        int not_rob = max(lv.first, lv.second) + max(rv.first, rv.second);
        return make_pair(rob, not_rob);
    }

    int rob(TreeNode* root) {
        pair<int, int> res = getVal(root);
        return max(res.first, res.second);
    }
};

int main() {
    return 0;
}
