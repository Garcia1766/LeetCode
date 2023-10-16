import java.util.HashSet;
import java.util.Set;

class Solution {
    public int singleNumber(int[] nums) {
        Set<Integer> mySet = new HashSet<>();
        for (int num : nums) {
            if (mySet.contains(num)) {
                mySet.remove(num);
            } else {
                mySet.add(num);
            }
        }
        for (int num : mySet) {
            return num;
        }
        return 0;
    }
}

public class Main {
    public static void main(String[] args) {
        int[] nums = {4,1,2,1,2};
        int res = new Solution().singleNumber(nums);
        System.out.println(res);
    }
}
