#include<iostream>
#include<vector>
#include<queue>
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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return NULL;
        if (key == root->val) {
            if (!root->left && !root->right) root = NULL;
            else if (root->left) {
                TreeNode *pre = root->left;
                TreeNode *prep = NULL;
                while (pre->right) {
                    prep = pre;
                    pre = pre->right;
                }
                root->val = pre->val;
                if (pre == root->left) {
                    root->left = pre->left;
                } else if (!pre->left) {  // pre is a leaf
                    prep->right = NULL;
                } else {
                    prep->right = pre->left;
                }
            } else {  // root->right
                TreeNode *post = root->right;
                TreeNode *postp = NULL;
                while (post->left) {
                    postp = post;
                    post = post->left;
                }
                root->val = post->val;
                if (post == root->right) {
                    root->right = post->right;
                } else if (!post->right) {  // pre is a leaf
                    postp->left = NULL;
                } else {
                    postp->left = post->right;
                }
            }
        } else if (key < root->val) {
            TreeNode *ret = deleteNode(root->left, key);
            if (!ret) root->left = NULL;
        } else {
            TreeNode *ret = deleteNode(root->right, key);
            if (!ret) root->right = NULL;
        }
        return root;
    }
};

int main() {
    TreeNode *root = new TreeNode(3, new TreeNode(9), new TreeNode(20, new TreeNode(15), new TreeNode(7)));
    TreeNode *root2 = new TreeNode();
    TreeNode *root3 = NULL;
    TreeNode *root4 = new TreeNode(4, new TreeNode(9, new TreeNode(5), new TreeNode(1)), new TreeNode(0));
    TreeNode *root5 = new TreeNode(5, new TreeNode(3, new TreeNode(2), new TreeNode(4)), new TreeNode(6, NULL, new TreeNode(7)));
    print_layerwise(root5);
    TreeNode* res = Solution().deleteNode(root5, 7);
    print_layerwise(root5);
    print_layerwise(res);
    return 0;
}