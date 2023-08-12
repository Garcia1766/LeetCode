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
    private void swap(TreeNode x, TreeNode y) {
        int tmp = x.val;
        x.val = y.val;
        y.val = tmp;
    }

    public void recoverTree(TreeNode root) {
        Stack<TreeNode> stk = new Stack<>();
        TreeNode cur = root, pred = null;
        TreeNode x = null, y = null;

        while (cur != null || !stk.empty()) {
            if (cur != null) {
                stk.push(cur);
                cur = cur.left;
            } else {
                cur = stk.pop();
                // process(cur);
                if (pred != null && cur.val < pred.val) {
                    y = cur;
                    if (x == null) x = pred;
                    else break;
                }
                pred = cur;
                cur = cur.right;
            }
        }
        swap(x, y);
    }
}

public class Main2 {
    public static void main(String[] args) {
        TreeNode root = new TreeNode(1, new TreeNode(3, null, new TreeNode(2)), null);
        new Solution().recoverTree(root);
        System.out.println(root);
    }
}
