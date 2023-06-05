class Solution {
    public int searchInsert(int[] nums, int target) {
        int n = nums.length;
        if (n == 1) return nums[0] >= target ? 0 : 1;

        int l = 0, r = n - 1, mid = (l + r) >> 1;
        while (r - l > 1) {
            if (nums[mid] > target) {
                r = mid;
                mid = (l + r) >> 1;
            } else if (nums[mid] < target) {
                l = mid;
                mid = (l + r) >> 1;
            } else {
                return mid;
            }
        }
        if (target <= nums[l]) return l;
        else if (target <= nums[r]) return r;
        else return r + 1;
    }
}

public class Main {
    public static void main(String[] args) {
        int[] nums = {1,3,5,6};
        int target = 7;
        int res = new Solution().searchInsert(nums, target);
        System.out.println(res);
    }
}
