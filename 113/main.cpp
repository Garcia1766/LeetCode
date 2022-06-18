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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> res;
        if (!root) return res;
        if (!root->left && !root->right) {
            if (targetSum == root->val)
                res.push_back({root->val});
            return res;
        }
        vector<vector<int>> lres = pathSum(root->left, targetSum - root->val);
        for (auto v : lres) {  // 此处立刻处理lres，比先递归右子树再一起处理lres和rres执行起来要快
            v.emplace(v.begin(), root->val);
            res.push_back(v);
        }
        vector<vector<int>> rres = pathSum(root->right, targetSum - root->val);
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
    vector<vector<int>> res = Solution().pathSum(root, 12);
    for (auto v : res){
        for (auto i : v)
            printf("%d ", i);
        printf("\n");
    }
    return 0;
}