#include<iostream>
#include<vector>
#include<stack>

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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        if (!root) return res;

        vector<pair<TreeNode*, int>> vec;
        vec.push_back(make_pair(root, 0));
        int pos = 0;
        while (pos < vec.size()) {
            if (vec[pos].first->right) vec.push_back(make_pair(vec[pos].first->right, vec[pos].second + 1));
            if (vec[pos].first->left) vec.push_back(make_pair(vec[pos].first->left, vec[pos].second + 1));
            pos++;
        }
        int max_depth = vec[vec.size() - 1].second;
        for (int i = vec.size() - 1; i >= 0; i--) {
            if (max_depth - vec[i].second >= res.size()) res.push_back(vector<int>());
            res[max_depth - vec[i].second].push_back(vec[i].first->val);
        }
        return res;
    }
};

int main() {
    TreeNode *root = new TreeNode(3, new TreeNode(9), new TreeNode(20, new TreeNode(15), new TreeNode(7)));
    TreeNode *root2 = new TreeNode();
    TreeNode *root3 = NULL;
    vector<vector<int>> res = Solution().levelOrderBottom(root3);
    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[i].size(); j++)
            printf("%d ", res[i][j]);
        printf("\n");
    }
    printf("\n");
    return 0;
}