import java.util.HashMap;
import java.util.Map;

class Solution {
    public int majorityElement(int[] nums) {
        Map<Integer, Integer> map = new HashMap<>();
        for (int num : nums) {
            if (map.containsKey(num)) {
                map.replace(num, map.get(num) + 1);
                if (map.get(num) > nums.length / 2) {
                    return num;
                }
            } else {
                map.put(num, 1);
            }
        }
        return 0;
    }
}

public class Main {
    public static void main(String[] args) {
        return;
    }
}
