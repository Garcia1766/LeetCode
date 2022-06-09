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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if (!root) return res;

        vector<pair<TreeNode*, int>> vec;
        vec.push_back(make_pair(root, 0));
        int pos = 0;
        while (pos < vec.size()) {
            if (vec[pos].first->left) vec.push_back(make_pair(vec[pos].first->left, vec[pos].second + 1));
            if (vec[pos].first->right) vec.push_back(make_pair(vec[pos].first->right, vec[pos].second + 1));
            pos++;
        }
        for (int i = 1; i < vec.size(); i++) {
            if (vec[i].second > vec[i-1].second) {
                res.push_back(vec[i-1].first->val);
            }
        }
        res.push_back(vec[vec.size() - 1].first->val);
        return res;
    }
};

int main() {
    TreeNode *root = new TreeNode(3, new TreeNode(9), new TreeNode(20, new TreeNode(15), new TreeNode(7)));
    TreeNode *root2 = new TreeNode();
    TreeNode *root3 = NULL;
    vector<int> res = Solution().rightSideView(root);
    for (int i = 0; i < res.size(); i++) {
        printf("%d ", res[i]);
    }
    printf("\n");
    return 0;
}