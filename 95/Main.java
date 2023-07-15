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
    private List<TreeNode> generateSubTrees(int num, int delta) {
        List<TreeNode> res = new ArrayList<TreeNode>();
        if (num <= 0) {
            res.add(null);
            return res;
        }
        if (num == 1) {
            res.add(new TreeNode(delta));
            return res;
        }
        for (int r = 0; r < num; ++r) {
            List<TreeNode> lSubTrees = generateSubTrees(r, delta);
            List<TreeNode> rSubTrees = generateSubTrees(num - 1 - r, delta + r + 1);
            for (int i = 0; i < lSubTrees.size(); ++i) {
                for (int j = 0; j < rSubTrees.size(); ++j) {
                    res.add(new TreeNode(r + delta, lSubTrees.get(i), rSubTrees.get(j)));
                }
            }
        }
        
        return res;
    }

    public List<TreeNode> generateTrees(int n) {
        List<TreeNode> res = new ArrayList<TreeNode>();
        if (n <= 1) {
            res.add(new TreeNode(1));
            return res;
        }

        return generateSubTrees(n, 1);
    }
}

public class Main {
    public static void main(String[] args) {
        int n = 3;
        List<TreeNode> res = new Solution().generateTrees(n);
        System.out.println(res);
    }
}
