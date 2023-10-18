class Solution {
    public int findMin(int[] nums) {
        int n = nums.length;
        if (nums[0] <= nums[n - 1]) return nums[0];

        int left = 0, right = n - 1;
        while (right - left > 1) {
            int mid = (left + right) >> 1;
            if (nums[mid] > nums[left]) {
                left = mid;
            } else if (nums[mid] < nums[right]) {
                right = mid;
            }
        }

        return nums[right];
    }
}

public class Main {
    public static void main(String[] args) {
        int[] nums = {4,5,6,7,0,1,2};
        int res = new Solution().findMin(nums);
        System.out.println(res);
        return;
    }
}
