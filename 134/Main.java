class Solution {
    public int canCompleteCircuit(int[] gas, int[] cost) {
        int n = gas.length;
        int[] delta = new int[n];
        for (int i = 0; i < n; ++i) {
            delta[i] = gas[i] - cost[i];
        }

        int min_idx = 0, min_val = delta[0], sum = delta[0];
        for (int i = 1; i < n; ++i) {
            sum += delta[i];
            if (sum <= min_val) {
                min_val = sum;
                min_idx = i;
            }
        }

        if (sum < 0) return -1;

        return min_idx == n - 1 ? 0 : min_idx + 1;
    }
}

public class Main {
    public static void main(String[] args) {
        int[] gas = {2,0,0,0,0}, cost = {0,1,0,0,0};
        int res = new Solution().canCompleteCircuit(gas, cost);
        System.out.println(res);
    }
}
