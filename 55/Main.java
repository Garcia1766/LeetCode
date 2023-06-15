class Solution {
    public boolean canJump(int[] nums) {
        int n = nums.length;
        if (n <= 1) return true;
        int cur_pos = 0;
        int max_pos = 0;
        while (cur_pos < n - 1) {
            max_pos = Math.max(max_pos, cur_pos + nums[cur_pos]);
            if (max_pos >= n - 1) return true;
            if (max_pos <= cur_pos) return false;
            cur_pos++;
        }
        return true;
    }
}

public class Main {
    public static void main(String[] args) {
        int[] nums = {2,3,1,1,4};
        boolean res = new Solution().canJump(nums);
        System.out.println(res);
    }
}
