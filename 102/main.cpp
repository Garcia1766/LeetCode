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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (!root) return res;
        queue<pair<TreeNode*, int>> que;
        que.push(make_pair(root, 0));
        while (!que.empty()) {
            pair<TreeNode*, int> nd = que.front();
            que.pop();
            if (nd.second == res.size()) res.push_back(vector<int>());  // else, nd.second < res.size()
            res[nd.second].push_back(nd.first->val);
            if (nd.first->left) que.push(make_pair(nd.first->left, nd.second + 1));
            if (nd.first->right) que.push(make_pair(nd.first->right, nd.second + 1));
        }
        return res;
    }
};

int main() {
    TreeNode *root = new TreeNode(3, new TreeNode(9), new TreeNode(20, new TreeNode(15), new TreeNode(7)));
    TreeNode *root2 = new TreeNode();
    TreeNode *root3 = NULL;
    vector<vector<int>> res = Solution().levelOrder(root3);
    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[i].size(); j++)
            printf("%d ", res[i][j]);
        printf("\n");
    }
    printf("\n");
    return 0;
}