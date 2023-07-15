import java.util.List;
import java.util.ArrayList;

class Solution {
    public List<List<Integer>> generate(int numRows) {
        List<List<Integer>> res = new ArrayList<List<Integer>>();
        List<Integer> curLine = new ArrayList<Integer>();
        curLine.add(1);
        res.add(curLine);
        if (numRows == 1) return res;

        for (int i = 1; i < numRows; ++i) {
            curLine = new ArrayList<Integer>();
            List<Integer> lastLine = res.get(res.size() - 1);
            curLine.add(1);
            for (int j = 1; j < i; ++j) {
                curLine.add(lastLine.get(j - 1) + lastLine.get(j));
            }
            curLine.add(1);
            res.add(curLine);
        }

        return res;
    }
}

public class Main {
    public static void main(String[] args) {
        int numRows = 5;
        List<List<Integer>> res = new Solution().generate(numRows);
        System.out.println(res);
    }
}
