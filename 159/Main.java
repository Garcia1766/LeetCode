import java.util.HashMap;
import java.util.Map;

class Solution {
    public int lengthOfLongestSubstringTwoDistinct(String s) {
        Map<Character, Integer> mp = new HashMap<>();
        int left = 0, right = 0, maxLength = 0;
        while (right < s.length()) {
            if (mp.containsKey(s.charAt(right))) {
                mp.put(s.charAt(right), mp.get(s.charAt(right)) + 1);
            } else {
                mp.put(s.charAt(right), 1);
            }
            right++;
            while (mp.size() > 2) {
                if (mp.get(s.charAt(left)) > 1) {
                    mp.put(s.charAt(left), mp.get(s.charAt(left)) - 1);
                } else {
                    mp.remove(s.charAt(left));
                }
                left++;
            }
            maxLength = Math.max(maxLength, right - left);
        }

        return maxLength;
    }
}

public class Main {
    public static void main(String[] args) {
        return;
    }
}
