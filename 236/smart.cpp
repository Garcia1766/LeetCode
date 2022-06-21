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
    // 本函数的完整功能为：
    // 1. 若p和q都不是root子代，返回NULL
    // 2. 若p和q只有有一个是root子代，返回该结点
    // 3. 若p和q都是root子代，返回二者的最低公共祖先
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) return NULL;
        if (root == p || root == q) return root;
        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);
        if (!left) return right;
        if (!right) return left;
        if (left && right) return root;
        return NULL;
    }
};

int main() {
    TreeNode *root = new TreeNode(3, new TreeNode(9), new TreeNode(20, new TreeNode(15), new TreeNode(7)));
    TreeNode *root2 = new TreeNode();
    TreeNode *root3 = NULL;
    TreeNode *root4 = new TreeNode(4, new TreeNode(9, new TreeNode(5), new TreeNode(1)), new TreeNode(0));
    TreeNode *root5 = new TreeNode(5, new TreeNode(3, new TreeNode(2), new TreeNode(4)), new TreeNode(6, NULL, new TreeNode(7)));
    vector<int> vec = {-10,-3,0,5,9};
    TreeNode* res = Solution().lowestCommonAncestor(root5, root5->left, root5->right);
    printf("%d\n", res->val);
    // print_inorder(res);
    // print_layerwise(res);
    return 0;
}