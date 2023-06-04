import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

class Solution {
    private List<List<String>> memo = new ArrayList<List<String>>() {
        {
            add(new ArrayList<String>(Arrays.asList("")));
        }
    };
    
    public List<String> generateParenthesis(int n) {
        if (n == 0) return memo.get(0);

        for (int i = 1; i <= n; ++i) {
            memo.add(new ArrayList<String>());
            for (int l = 0; l < i; ++l) {
                for (String lStr : memo.get(l)) {
                    for (String rStr : memo.get(i - l - 1)) {
                        memo.get(i).add("(" + lStr + ")" + rStr);
                    }
                }
            }
        }

        return memo.get(n);
    }
}

public class Main {
    public static void main(String[] args) {
        int n = 3;
        List<String> res = new Solution().generateParenthesis(n);
        System.out.println(res);
    }
}
