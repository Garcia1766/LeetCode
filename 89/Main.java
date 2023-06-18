import java.util.ArrayList;
import java.util.List;

class Solution {
    public List<Integer> grayCode(int n) {
        List<Integer> res = new ArrayList<>();
        res.add(0);

        for (int i = 1; i <= n; ++i) {
            int mask = 1 << (i - 1);
            int preSize = res.size();
            for (int j = preSize - 1; j >= 0; --j) {
                res.add(res.get(j) + mask);
            }
        }
        return res;
    }
}

public class Main {
    public static void main(String[] args) {
        int n = 3;
        List<Integer> res = new Solution().grayCode(n);
        System.out.println(res);
    }
}
