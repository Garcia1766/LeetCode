class Solution {
    public int[] searchRange(int[] nums, int target) {
        int n = nums.length;
        int[] res = {-1, -1};
        if (n == 0) return res;
        if (n == 1) return target == nums[0] ? new int[]{0, 0} : res;
        if (target > nums[n - 1] || target < nums[0]) return res;

        int l = 0, r = n - 1, midl = (l + r) >> 1, midr = midl;
        while (r - l > 1) {
            if (nums[midl] > target) {
                r = midl;
                midl = midr = (l + r) >> 1;
            } else if (nums[midl] < target) {
                l = midl;
                midl = midr = (l + r) >> 1;
            } else { // nums[midl] == nums[midr] == target
                int ll = (l + midl) >> 1, rr = (midr + r) >> 1;
                while (midl - l > 1) {
                    if (nums[ll] < target) {
                        l = ll;
                        ll = (l + midl) >> 1;
                    } else { // nums[ll] == target == nums[midl]
                        midl = ll;
                        ll = (l + midl) >> 1;
                    }
                }
                while (r - midr > 1) {
                    if (nums[rr] > target) {
                        r = rr;
                        rr = (midr + r) >> 1;
                    } else { // nums[rr] == target == nums[midr]
                        midr = rr;
                        rr = (midr + r) >> 1;
                    }
                }
                res[0] = nums[l] == target ? l : midl;
                res[1] = nums[r] == target ? r : midr;
                return res;
            }
        }
        if (nums[l] == target && nums[r] == target) {
            res[0] = l;
            res[1] = r;
        } else if (nums[l] == target) {
            res[0] = res[1] = l;
        } else if (nums[r] == target) {
            res[0] = res[1] = r;
        }
        return res;
    }
}

public class Main {
    public static void main(String[] args) {
        int[] nums = {5,7,7,8,8,10};
        int target = 10;
        int[] res = new Solution().searchRange(nums, target);
        System.out.printf("[%d,%d]\n", res[0], res[1]);
    }
}
