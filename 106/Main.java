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
    private int[] inorder, postorder;

    private TreeNode buildSubtree(int i_start, int i_end, int p_start, int p_end) {
        if (i_end - i_start <= 0) return null;
        TreeNode subroot = new TreeNode(postorder[p_end - 1]);
        if (i_end - i_start == 1) return subroot;
        int i_pos = i_start;
        while (inorder[i_pos] != postorder[p_end - 1]) i_pos++;
        TreeNode subright = buildSubtree(i_pos + 1, i_end, p_end - i_end + i_pos, p_end - 1);
        TreeNode subleft = buildSubtree(i_start, i_pos, p_start, p_end - i_end + i_pos);
        subroot.left = subleft;
        subroot.right = subright;
        return subroot;
    }

    public TreeNode buildTree(int[] inorder, int[] postorder) {
        this.inorder = inorder;
        this.postorder = postorder;
        return buildSubtree(0, inorder.length, 0, postorder.length);
    }
}

public class Main {
    public static void main(String[] args) {
        int[] inorder = {9,3,15,20,7}, postorder = {9,15,7,20,3};
        TreeNode res = new Solution().buildTree(inorder, postorder);
        System.out.println(res);
    }
}
