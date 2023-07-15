import java.util.List;
import java.util.ArrayList;

// use only half memory
class Solution {
    public List<Integer> getRow(int rowIndex) {
        List<Integer> res = new ArrayList<>(rowIndex + 1) { // 提前指定capacity, 减少内存开销
            {
                add(1);
            }
        };

        for (int i = 1; i <= rowIndex; ++i) {
            for (int j = i - 1; j > 0; --j) { // 倒着更新，就不用额外存一个List
                res.set(j, res.get(j - 1) + res.get(j));
            }
            res.add(1);
        }
        return res;
    }
}

public class Main2 {
    public static void main(String[] args) {
        int rowIndex = 5;
        List<Integer> res = new Solution().getRow(rowIndex);
        System.out.println(res);
    }
}
