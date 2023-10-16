import java.util.HashMap;
import java.util.Map;

class Solution {
    public int singleNumber(int[] nums) {
        Map<Integer, Integer> myMap = new HashMap<>();
        for (int num : nums) {
            myMap.put(num, myMap.getOrDefault(num, 0) + 1);
        }
        for (int num : nums) {
            if (myMap.get(num) == 1) {
                return num;
            }
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
