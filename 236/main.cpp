#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<cassert>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void print_inorder(TreeNode* root) {
    if (!root) return;
    stack<TreeNode*> stk;
    while (root || !stk.empty()) {
        while (root) {
            stk.push(root);
            root = root->left;
        }
        root = stk.top();
        stk.pop();
        printf("%d ", root->val);
        root = root->right;
    }
    printf("\n");
}

void print_layerwise(TreeNode *root) {
    if (!root) return;
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()) {
        TreeNode *cur = q.front();
        q.pop();
        if (!cur) printf("null ");
        else {
            printf("%d ", cur->val);
            q.push(cur->left);
            q.push(cur->right);
        }
    }
    printf("\n");
}

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> pathp = findPath(root, p);
        vector<TreeNode*> pathq = findPath(root, q);
        int i = 0;
        for (; i < min(pathp.size(), pathq.size()); i++) {
            if (pathp[i]->val != pathq[i]->val) break;
        }
        assert(i >= 1);
        return pathp[i - 1];
    }
    vector<TreeNode*> findPath(TreeNode *root, TreeNode *p) {
        vector<TreeNode*> res;
        if (!root) return res;
        if (root->val == p->val) {
            res.push_back(root);
            return res;
        }
        vector<TreeNode*> lpath = findPath(root->left, p);
        if (lpath.size() > 0) {
            lpath.emplace(lpath.begin(), root);
            return lpath;
        }
        vector<TreeNode*> rpath = findPath(root->right, p);
        if (rpath.size() > 0) {
            rpath.emplace(rpath.begin(), root);
            return rpath;
        }
        return res;
    }
};

int main() {
    TreeNode *root = new TreeNode(3, new TreeNode(9), new TreeNode(20, new TreeNode(15), new TreeNode(7)));
    TreeNode *root2 = new TreeNode();
    TreeNode *root3 = NULL;
    TreeNode *root4 = new TreeNode(4, new TreeNode(9, new TreeNode(5), new TreeNode(1)), new TreeNode(0));
    TreeNode *root5 = new TreeNode(5, new TreeNode(3, new TreeNode(2), new TreeNode(4)), new TreeNode(6, NULL, new TreeNode(7)));
    vector<int> vec = {-10,-3,0,5,9};
    TreeNode* res = Solution().lowestCommonAncestor(root5, new TreeNode(3), new TreeNode(6));
    printf("%d\n", res->val);
    // print_inorder(res);
    // print_layerwise(res);
    return 0;
}