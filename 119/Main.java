import java.util.List;
import java.util.ArrayList;

class Solution {
    public List<Integer> getRow(int rowIndex) {
        List<Integer> res = new ArrayList<>();
        res.add(1);
        if (rowIndex == 0) return res;
        res.add(1);
        if (rowIndex == 1) return res;

        for (int i = 2; i <= rowIndex; ++i) {
            List<Integer> nextRow = new ArrayList<>();
            nextRow.add(1);
            for (int j = 1; j < i; ++j) {
                nextRow.add(res.get(j - 1) + res.get(j));
            }
            nextRow.add(1);
            res = nextRow;
        }
        return res;
    }
}

public class Main {
    public static void main(String[] args) {
        int rowIndex = 5;
        List<Integer> res = new Solution().getRow(rowIndex);
        System.out.println(res);
    }
}
