package Template.Tree;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
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
    public List<Integer> preorderTraverse(TreeNode root) {
        List<Integer> res = new ArrayList<>();
        if (root == null) return res;

        Stack<TreeNode> stk = new Stack<>();
        stk.push(root);
        while (!stk.empty()) {
            TreeNode cur = stk.pop();
            res.add(cur.val);
            if (cur.right != null) stk.push(cur.right);
            if (cur.left != null) stk.push(cur.left);
        }

        return res;
    }

    public List<Integer> inorderTraverse(TreeNode root) {
        List<Integer> res = new ArrayList<>();
        if (root == null) return res;

        Stack<TreeNode> stk = new Stack<>();
        TreeNode cur = root;

        while (cur != null || !stk.empty()) {
            if (cur != null) {
                stk.push(cur);
                cur = cur.left;
            } else {
                cur = stk.pop();
                res.add(cur.val);
                cur = cur.right;
            }
        }

        return res;
    }

    public List<Integer> postorderTraverse(TreeNode root) {
        List<Integer> res = new ArrayList<>();
        if (root == null) return res;

        Stack<TreeNode> stk = new Stack<>();
        stk.push(root);
        while (!stk.empty()) {
            TreeNode cur = stk.pop();
            res.add(cur.val);
            if (cur.left != null) stk.push(cur.left);
            if (cur.right != null) stk.push(cur.right);
        }

        Collections.reverse(res);
        return res;
    }
}

public class Traverse {
    public static void main(String[] args) {
        return;
    }
}
