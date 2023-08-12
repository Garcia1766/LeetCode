import java.util.ArrayList;
import java.util.List;

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
    private void inOrder(TreeNode root, List<Integer> nums) {
        if (root == null) return;
        inOrder(root.left, nums);
        nums.add(root.val);
        inOrder(root.right, nums);
    }

    private int[] findTwoSwapped(List<Integer> nums) {
        int x = -1, y = -1;
        boolean first_occurrance = false;
        for (int i = 0; i < nums.size() - 1; ++i) {
            if (nums.get(i) > nums.get(i + 1)) {
                y = nums.get(i + 1);
                if (!first_occurrance) {
                    x = nums.get(i);
                    first_occurrance = true;
                } else break;
            }
        }
        return new int[]{x, y};
    }

    private void recover(TreeNode root, int count, int x, int y) {
        if (root != null) {
            if (root.val == x || root.val == y) {
                root.val = root.val == x ? y : x;
                count--;
                if (count == 0) return;
            }
            recover(root.left, count, x, y);
            recover(root.right, count, x, y);
        }
    }

    public void recoverTree(TreeNode root) {
        List<Integer> nums = new ArrayList<>();
        inOrder(root, nums);
        int[] toBeSwapped = findTwoSwapped(nums);
        recover(root, 2, toBeSwapped[0], toBeSwapped[1]);
    }
}

public class Main {
    public static void main(String[] args) {
        TreeNode root = new TreeNode(1, new TreeNode(3, null, new TreeNode(2)), null);
        new Solution().recoverTree(root);
        System.out.println(root);
    }
}
