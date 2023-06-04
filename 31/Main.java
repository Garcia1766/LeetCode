class Solution {
    private void reverse(int[] nums, int start, int end) {
        int tmp;
        while (start < end) {
            tmp = nums[start];
            nums[start] = nums[end];
            nums[end] = tmp;
            start++;
            end--;
        }
    }

    public void nextPermutation(int[] nums) {
        int n = nums.length;
        if (n == 1) return;

        int start = n - 1;
        while (start > 0 && nums[start - 1] >= nums[start]) {
                start--;
        }
        if (start == 0) {
            reverse(nums, 0, n - 1);
            return;
        }

        int val = nums[start - 1];
        int l = start, r = n - 1, mid = (l + r) >> 1;
        while (r - l > 1) {
            if (nums[mid] > val) {
                l = mid;
                mid = (l + r) >> 1;
            } else {  // nums[mid] <= val
                r = mid;
                mid = (l + r) >> 1;
            }
        }
        if (nums[r] > val) l = r;
        nums[start - 1] = nums[l];
        nums[l] = val;
        reverse(nums, start, n - 1);
    }
}

public class Main {
    public static void main(String[] args) {
        int[] nums = {1,1,5};
        new Solution().nextPermutation(nums);
        for (int num : nums) {
            System.out.printf("%d ", num);
        }
        System.out.println();
    }
}
