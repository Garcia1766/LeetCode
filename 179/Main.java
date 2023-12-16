import java.util.Arrays;
import java.util.Comparator;

class StrCmp implements Comparator<String> {
    @Override
    public int compare(String a, String b) {
        // Cannot directly compare a and b. The desired comparison is between a+b and b+a
        String s1 = a + b, s2 = b + a;
        return s2.compareTo(s1);
    }
}

class Solution {
    public String largestNumber(int[] nums) {
        String[] Nums = new String[nums.length];
        for (int i = 0; i < nums.length; ++i) {
            Nums[i] = String.valueOf(nums[i]);
        }
        Arrays.sort(Nums, new StrCmp());
        if (Nums[0].equals("0")) return "0"; // Don't use Nums[0] == "0"

        StringBuilder sbd = new StringBuilder();
        for (String s : Nums) {
            sbd.append(s);
        }
        return sbd.toString();
    }
}

public class Main {
    public static void main(String[] args) {
        int[] nums = {0,0};
        String res = new Solution().largestNumber(nums);
        System.out.println(res);
    }
}
