#include<iostream>
#include<vector>
#include<queue>
#include<cmath>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void print_tree(TreeNode* root) {
    if (!root) return;
    queue<TreeNode*> q({root});
    while(!q.empty()) {
        TreeNode *cur = q.front();
        q.pop();
        printf("%d ", cur->val);
        if (cur->left) q.push(cur->left);
        if (cur->right) q.push(cur->right);
    }
    printf("\n");
}

class Solution {
public:
    int countNodes1(TreeNode* root) {  // O(n)
        if (!root) return 0;
        return countNodes(root->left) + countNodes(root->right) + 1;
    }
    int countNodes2(TreeNode* root) {  // O()
        if (!root) return 0;
        int ld = getDepth(root->left), rd = getDepth(root->right);
        if (ld == rd) {
            return 1 + ((1 << ld) - 1) + countNodes(root->right);
        } else {
            return 1 + countNodes(root->left) + ((1 << rd) - 1);
        }
    }
    int getDepth(TreeNode* root) {
        if (!root) return 0;
        return 1 + getDepth(root->left);
    }
    // makes sure on each level/depth of the tree, only one node can possibly trigger the recursion,
    // therefore it becomes h (height of the tree=logN) + (h-1) + (h-2)...+1 = O(h^2) = O(logN*logN)
    int countNodes(TreeNode* root) {
        if (!root) return 0;
        int ld = 0, rd = 0;
        TreeNode *l = root->left, *r = root->right;
        while(l) {l = l->left; ld++;}
        while(r) {r = r->right; rd++;}
        if (ld == rd) return (1 << ld + 1) - 1;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};

int main() {
    TreeNode *root = new TreeNode(1, new TreeNode(2, new TreeNode(3), new TreeNode(4)),
        new TreeNode(2, new TreeNode(4), new TreeNode(3)));
    // TreeNode *root2 = new TreeNode();
    // TreeNode *root3 = NULL;
    // TreeNode *p = new TreeNode(1, new TreeNode(2), new TreeNode(3));
    // TreeNode *q = new TreeNode(1, new TreeNode(2), new TreeNode(3));
    int res = Solution().countNodes(root);
    printf("%d\n", res);
    return 0;
}