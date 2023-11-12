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
    public TreeNode upsideDownBinaryTree(TreeNode root) {
        if (root == null || root.left == null) return root;

        TreeNode prev = null;
        TreeNode cur = root;
        TreeNode curRight = null;
        TreeNode next = cur.left;

        while (cur != null) {
            cur.left = curRight;
            curRight = cur.right;
            cur.right = prev;
            prev = cur;
            cur = next;
            next = cur == null ? null : cur.left;
        }

        return prev;
    }
}

public class Main {
    public static void main(String[] args) {
        return;
    }
}
