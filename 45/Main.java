// dp, O(n^2)
class Solution {
    public int jump(int[] nums) {
        int n = nums.length;
        if (n == 1) return 0;

        int[] jumps = new int[n];
        for (int i = 1; i < n; ++i) {
            jumps[i] = Integer.MAX_VALUE;
        }

        for (int i = 0; i < n - 1; ++i) {
            for (int j = i + 1; j < n && j <= i + nums[i]; ++j) {
                jumps[j] = Math.min(jumps[j], jumps[i] + 1);
            }
        }

        return jumps[n - 1];
    }
}

public class Main {
    public static void main(String[] args) {
        int[] nums = {2,3,0,1,4};
        int res = new Solution().jump(nums);
        System.out.println(res);
    }
}
