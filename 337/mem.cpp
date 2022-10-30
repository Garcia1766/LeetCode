#include<iostream>
#include<unordered_map>

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
    unordered_map<TreeNode*, int> m_rob;
    unordered_map<TreeNode*, int> m_not_rob;
    // <rob_this_node, not_rob_this_node>
    int getVal(TreeNode* root, bool rb) {
        if (!root) return 0;
        if (rb) {
            if (m_rob.find(root) != m_rob.end()) {
                return m_rob[root];
            }
            int res = getVal(root->left, false) + getVal(root->right, false) + root->val;
            m_rob[root] = res;
            return res;
        } else {
            if (m_not_rob.find(root) != m_not_rob.end()) {
                return m_not_rob[root];
            }
            int res = max(getVal(root->left, true), getVal(root->left, false)) + max(getVal(root->right, true), getVal(root->right, false));
            m_not_rob[root] = res;
            return res;
        }
    }

    int rob(TreeNode* root) {
        return max(getVal(root, true), getVal(root, false));
    }
};

int main() {
    TreeNode* root1 = new TreeNode(3, new TreeNode(2, NULL, new TreeNode(3)), new TreeNode(3, NULL, new TreeNode(1)));
    TreeNode* root2 = new TreeNode(3, new TreeNode(4, new TreeNode(1), new TreeNode(3)), new TreeNode(5, NULL, new TreeNode(1)));
    int res = Solution().rob(root2);
    printf("%d\n", res);
    return 0;
}
