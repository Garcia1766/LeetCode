class Solution {
    private int searchAscending(int[] nums, int start, int end, int target) {
        int l = start, r = end;
        if (target < nums[l] || target > nums[r]) return -1;
        int mid = (l + r) >> 1;
        while (r - l > 1) {
            if (nums[mid] > target) {
                r = mid;
                mid = (l + r) >> 1;
            } else if (nums[mid] < target) {
                l = mid;
                mid = (l + r) >> 1;
            } else { // nums[mid] == nums[target]
                return mid;
            }
        }
        if (nums[r] == target) return r;
        else if (nums[l] == target)  return l;
        return -1;
    }

    public int search(int[] nums, int target) {
        int n = nums.length;
        if (nums[0] < nums[n - 1]) return searchAscending(nums, 0, n - 1, target);

        int l = 0, r = n - 1, mid = (l + r) >> 1;
        while (r - l > 1) {
            if (nums[mid] > nums[l]) {
                l = mid;
                mid = (l + r) >> 1;
            } else { // nums[mid] < nums[r]
                r = mid;
                mid = (l + r) >> 1;
            }
        }
        if (target >= nums[0]) return searchAscending(nums, 0, l, target);
        else if (target <= nums[n - 1]) return searchAscending(nums, r, n - 1, target);
        return -1;
    }
}

public class Main {
    public static void main(String[] args) {
        int[] nums = {4,5,6,7,0,1,2};
        int target = 3;
        int res = new Solution().search(nums, target);
        System.out.println(res);
    }
}
