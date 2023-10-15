import java.util.Stack;

class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode() {}
    TreeNode(int val) { this.val = val; }
    TreeNode(int val, TreeNode left, TreeNode right) {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}

class Solution {
    public void flatten(TreeNode root) {
        if (root == null) return;

        Stack<TreeNode> stk = new Stack<>();
        TreeNode cur = root, prev = null;
        while (cur != null || !stk.empty()) {
            if (cur != null) {
                if (cur.right != null) {
                    stk.push(cur.right);
                    cur.right = null;
                }
                prev = cur;
                cur = cur.left;
            } else {
                cur = stk.pop();
                prev.left = cur;
            }
        }
    }
}

public class Main2 {
    public static void main(String[] args) {
        return;
    }
}
