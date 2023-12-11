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

class BSTIterator {
    Stack<TreeNode> stk;
    TreeNode cur;

    public BSTIterator(TreeNode root) {
        this.stk = new Stack<>();
        cur = root;
    }
    
    public int next() {
        int res = -1;
        while (cur != null || !stk.empty()) {
            if (cur != null) {
                stk.push(cur);
                cur = cur.left;
            } else {
                cur = stk.pop();
                res = cur.val;
                cur = cur.right;
                break;
            }
        }
        return res;
    }
    
    public boolean hasNext() {
        return cur != null || !stk.empty();
    }
}

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator obj = new BSTIterator(root);
 * int param_1 = obj.next();
 * boolean param_2 = obj.hasNext();
 */

public class Main {
    public static void main(String[] args) {
        return;
    }
}
