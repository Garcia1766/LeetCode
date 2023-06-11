import java.util.ArrayList;
import java.util.List;

class Solution {
    private List<Integer> reverseIntList (List<Integer> intList) {
        int n = intList.size();
        int l = 0, r = n - 1;
        while (l < r) {
            int tmp = intList.get(l);
            intList.set(l, intList.get(r));
            intList.set(r, tmp);
            l++;
            r--;
        }
        return intList;
    }

    public List<Integer> addToArrayForm(int[] num, int k) {
        List<Integer> kList = new ArrayList<>();
        while (k != 0) {
            kList.add(0, k % 10);
            k /= 10;
        }

        int[] kk = kList.stream().mapToInt(Integer::intValue).toArray();
        int m = num.length, n = kk.length;
        // System.out.println(Arrays.stream(kk).boxed().toList());

        List<Integer> res = new ArrayList<>();
        int i = m - 1, j = n - 1;
        int carry = 0;
        while (i >= 0 || j >= 0) {
            int x = i >= 0 ? num[i] : 0;
            int y = j >= 0 ? kk[j] : 0;
            int sum = (x + y + carry) % 10;
            carry = (x + y + carry) / 10;
            res.add(sum);
            if (i >= 0) i--;
            if (j >= 0) j--;
        }
        if (carry != 0) {
            res.add(carry);
        }
        
        return reverseIntList(res);
    }
}

public class Main {
    public static void main(String[] args) {
        int[] num = {1,2,0,0};
        int k = 34;
        List<Integer> res = new Solution().addToArrayForm(num, k);
        System.out.println(res);
    }
}
