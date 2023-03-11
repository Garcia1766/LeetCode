import java.util.ArrayList;
import java.util.List;

class Solution {
    public int lengthOfLIS(int[] nums) {
        List<Integer> sub = new ArrayList<>();
        sub.add(nums[0]);
        for (int i = 1; i < nums.length; ++i) {
            if (nums[i] > sub.get(sub.size() - 1)) {
                sub.add(nums[i]);
            } else {
                // find minimum j s.t. sub.get(j) >= nums[i]
                int j = binarySearch(nums[i], sub);
                sub.set(j, nums[i]);
            }
        }
        return sub.size();
    }

    private int binarySearch(int num, List<Integer> sub) {
        // num <= sub.get(r)
        int l = 0;
        int r = sub.size() - 1;
        int m = (l + r) / 2;
        while (l < r) {
            if (num <= sub.get(l)) {
                return l;
            }
            if (num <= sub.get(m)) {
                r = m;
                m = (l + r) / 2;
            } else {
                l = m + 1;
                m = (l + r) / 2;
            }
        }
        return l;
    }
}

public class Opt {
    public static void main(String[] args) {
        int[] nums = {4,10,4,3,8,9};
        int res = new Solution().lengthOfLIS(nums);
        System.out.println(res);
    }
}
