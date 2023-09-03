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
    private int[] preorder, inorder;

    private TreeNode buildSubtree(int p_start, int p_end, int i_start, int i_end) {
        if (p_end - p_start <= 0) return null;
        TreeNode subroot = new TreeNode(preorder[p_start]);
        if (p_end - p_start == 1) return subroot;
        int i_pos = i_start;
        while (inorder[i_pos] != preorder[p_start]) i_pos++;
        TreeNode subleft = buildSubtree(p_start + 1, p_start + 1 + i_pos - i_start, i_start, i_pos);
        TreeNode subright = buildSubtree(p_start + 1 + i_pos - i_start, p_end, i_pos + 1, i_end);
        subroot.left = subleft;
        subroot.right = subright;
        return subroot;
    }

    public TreeNode buildTree(int[] preorder, int[] inorder) {
        this.preorder = preorder;
        this.inorder = inorder;
        return buildSubtree(0, preorder.length, 0, inorder.length);
    }
}

public class Main {
    public static void main(String[] args) {
        int[] preorder = {3,9,20,15,7}, inorder = {9,3,15,20,7};
        TreeNode res = new Solution().buildTree(preorder, inorder);
        System.out.println(res);
    }
}
