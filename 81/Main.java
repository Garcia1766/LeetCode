class Solution {
    private boolean searchAscending(int[] nums, int start, int end, int target) {
        int l = start, r = end;
        if (l > r || target < nums[l] || target > nums[r]) return false;
        int mid = (l + r) >> 1;
        while (l <= r) {
            if (target < nums[mid]) {
                r = mid - 1;
            } else if (target > nums[mid]) {
                l = mid + 1;
            } else { // nums[mid] == nums[target]
                return true;
            }
            mid = (l + r) >> 1;
        }
        return false;
    }

    public boolean searchRange(int[] nums, int start, int end, int target) {
        if (start >= end || nums[start] < nums[end]) return searchAscending(nums, start, end, target);

        int l = start, r = end, mid = (l + r) >> 1;
        if (nums[mid] > nums[l]) {
            return searchAscending(nums, l, mid, target) || searchRange(nums, mid + 1, r, target);
        } else if (nums[mid] < nums[r]) {
            return searchRange(nums, l, mid - 1, target) || searchAscending(nums, mid, r, target);
        } else {
            if (nums[mid] == target) return true;
            else return searchRange(nums, l, mid - 1, target) || searchRange(nums, mid + 1, r, target);
        }
    }

    public boolean search(int[] nums, int target) {
        return searchRange(nums, 0, nums.length - 1, target);
    }
}

public class Main {
    public static void main(String[] args) {
        int[] nums = {2,5,6,0,0,1,2};
        int target = 3;
        boolean res = new Solution().search(nums, target);
        System.out.println(res);
    }
}
