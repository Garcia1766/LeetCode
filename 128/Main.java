import java.util.HashSet;
import java.util.Set;

class Solution {
    public int longestConsecutive(int[] nums) {
        Set<Integer> numSet = new HashSet<>();
        for (int num : nums) {
            numSet.add(num);
        }
        int longestStreak = 1;
        for (int num : numSet) {  // Using numSet instead of nums is much faster
            if (!numSet.contains(num - 1)) {
                int currentNum = num;
                int currentStreak = 1;
                while (numSet.contains(currentNum + 1)) {
                    currentNum++;
                    currentStreak++;
                }
                longestStreak = currentStreak > longestStreak ? currentStreak : longestStreak;
            }
        }
        return longestStreak;
    }
}

public class Main {
    public static void main(String[] args) {
        int[] nums = {100,4,200,1,3,2};
        int res = new Solution().longestConsecutive(nums);
        System.out.println(res);
    }
}
 