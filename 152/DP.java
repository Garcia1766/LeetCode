class Solution {
    public int maxProduct(int[] nums) {
        int n = nums.length;
        if (n == 1) return nums[0];
        
        int max_so_far = nums[0];  // max product so far containing nums[i]
        int min_so_far = nums[0];
        int res = max_so_far;
        for (int i = 1; i < n; ++i) {
            int tmp_max = Math.max(nums[i], Math.max(max_so_far * nums[i], min_so_far * nums[i]));
            min_so_far = Math.min(nums[i], Math.min(max_so_far * nums[i], min_so_far * nums[i]));
            max_so_far = tmp_max;
            res = Math.max(res, max_so_far);
        }
        return res;
    }
}

public class DP {
    public static void main(String[] args) {
        int[] nums = {-2,3,-4};
        int res = new Solution().maxProduct(nums);
        System.out.println(res);
    }
}
