class Solution {
    public int numTrees(int n) {
        if (n <= 1) return 1;
        int[] memo = new int[n + 1];
        memo[0] = memo[1] = 1;
        for (int i = 2; i <= n; ++i) {
            int tmp = 0;
            for (int j = 0; j < i; ++j) {
                tmp += memo[j] * memo[i - 1 - j];
            }
            memo[i] = tmp;
        }
        return memo[n];
    }
}

public class Main {
    public static void main(String[] args) {
        int n = 3;
        int res = new Solution().numTrees(n);
        System.out.println(res);
    }
}
