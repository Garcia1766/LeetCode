import java.util.Random;

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
    private int[] nums;
    private Random rand = new Random();

    private TreeNode subSort(int left, int right) {
        if (left >= right) return null;
        int p = (left + right - 1) / 2;
        if ((left + right - 1) % 2 == 1) p += rand.nextInt(2);
        TreeNode root = new TreeNode(nums[p]);
        TreeNode l = subSort(left, p);
        TreeNode r = subSort(p + 1, right);
        root.left = l;
        root.right = r;
        return root;
    }

    public TreeNode sortedArrayToBST(int[] nums) {
        this.nums = nums;
        int n = nums.length;
        TreeNode res = subSort(0, n);

        return res;
    }
}

public class Main {
    public static void main(String[] args) {
        int[] nums = {-10,-3,0,5,9};
        TreeNode res = new Solution().sortedArrayToBST(nums);
        System.out.println(res);
    }
}
