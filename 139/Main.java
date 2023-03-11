import java.util.Arrays;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

class Solution {
    public boolean wordBreak(String s, List<String> wordDict) {
        int l = s.length();
        Set<String> wordDictSet = new HashSet<>(wordDict);
        boolean[] dp = new boolean[l + 1];
        dp[0] = true;
        for (int i = 1; i < l + 1; ++i) {
            for (int j = 0; j < i; ++j) {
                if (dp[j] && wordDictSet.contains(s.substring(j, i))) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[l];
    }
}

public class Main {
    public static void main(String[] args) {
        String s = "catsandog";
        String[] wordDict = {"cats","dog","sand","and","cat"};
        boolean res = new Solution().wordBreak(s, Arrays.asList(wordDict));
        System.out.println(res);
    }
}
