class Solution {
    private int[] nums;

    public int findMin(int[] nums) {
        int n = nums.length;
        this.nums = nums;

        if (nums[0] < nums[n - 1]) return nums[0];

        return findMinSub(0, n - 1);
    }

    private int findMinSub(int l, int r) { // find min between [l, r]
        System.out.printf("Finding min in: [%d,%d] ", l, r);
        printVec(l, r);
        if (nums[l] < nums[r]) return nums[l];
        if (r - l <= 1) return nums[r];

        // nums[l] >= nums[r]
        int left = l, right = r, mid = (left + right) >> 1;
        while (right - left > 1) {
            if (nums[mid] > nums[left]) {
                left = mid;
            } else if (nums[mid] < nums[right]) {
                right = mid;
            } else { // nums[mid] == nums[left] || nums[mid] == nums[right]
                break;
            }
            mid = (left + right) >> 1;
        }
        if (right - left <= 1) return nums[right];

        int leftMin = findMinSub(left, mid);
        int rightMin = findMinSub(mid + 1, right);

        return Math.min(leftMin, rightMin);
    }

    private void printVec(int l, int r) {
        for (int i = l; i <= r && i < nums.length; ++i) {
            System.out.print(nums[i]);
            System.out.print(',');
        }
        System.out.println();
    }
}

public class Main {
    public static void main(String[] args) {
        int[] nums = {2,2,2,0,1};
        int res = new Solution().findMin(nums);
        System.out.println(res);
        return;
    }
}
