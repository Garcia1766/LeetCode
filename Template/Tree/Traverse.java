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
            TreeNode curNode = stk.pop();
            res.add(curNode.val);
            if (curNode.right != null) stk.push(curNode.right);
            if (curNode.left != null) stk.push(curNode.left);
        }

        return res;
    }

    public List<Integer> postorderTraverse(TreeNode root) {
        List<Integer> res = new ArrayList<>();
        if (root == null) return res;

        Stack<TreeNode> stk = new Stack<>();
        stk.push(root);

        while (!stk.empty()) {
            TreeNode curNode = stk.pop();
            res.add(curNode.val);
            if (curNode.right != null) stk.push(curNode.right);
            if (curNode.left != null) stk.push(curNode.left);
        }

        Collections.reverse(res);
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
}

public class Traverse {
    public static void main(String[] args) {
        return;
    }
}
