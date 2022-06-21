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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return sortedArrayToBST(nums, 0, nums.size());
    }
    TreeNode* sortedArrayToBST(vector<int>& nums, int start, int end) {
        if (end - start == 0) return NULL;
        if (end - start == 1) return new TreeNode(nums[start]);
        int mid = (start + end) >> 1;
        return new TreeNode(nums[mid], sortedArrayToBST(nums, start, mid), sortedArrayToBST(nums, mid + 1, end));
    }
};

int main() {
    TreeNode *root = new TreeNode(3, new TreeNode(9), new TreeNode(20, new TreeNode(15), new TreeNode(7)));
    TreeNode *root2 = new TreeNode();
    TreeNode *root3 = NULL;
    TreeNode *root4 = new TreeNode(4, new TreeNode(9, new TreeNode(5), new TreeNode(1)), new TreeNode(0));
    TreeNode *root5 = new TreeNode(5, new TreeNode(3, new TreeNode(2), new TreeNode(4)), new TreeNode(6, NULL, new TreeNode(7)));
    vector<int> vec = {-10,-3,0,5,9};
    TreeNode* res = Solution().sortedArrayToBST(vec);
    print_inorder(res);
    print_layerwise(res);
    return 0;
}