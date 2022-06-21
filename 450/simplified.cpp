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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return NULL;
        if (key < root->val) {
            root->left = deleteNode(root->left, key);
        } else if (key > root->val) {
            root->right = deleteNode(root->right, key);
        } else {  // key == root->val
            if (!root->left) {
                root = root->right;
            } else if (!root->right) {
                root = root->left;
            } else {  // root->left && root->right
                TreeNode *pred = findPred(root);
                root->val = pred->val;
                root->left = deleteNode(root->left, pred->val);
            }
        }
        return root;
    }
private:
    TreeNode* findPred(TreeNode* root) {
        assert(root && root->left);
        TreeNode* pred = root->left;
        while (pred->right) pred = pred->right;
        return pred;
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