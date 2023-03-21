class Solution {
    public int maxDotProduct(int[] nums1, int[] nums2) {
        int m = nums1.length;
        int n = nums2.length;
        int[][] dp = new int[m][n];
        dp[0][0] = nums1[0] * nums2[0];
        for (int j = 1; j < n; ++j) {
            int prod = nums1[0] * nums2[j];
            dp[0][j] = Math.max(dp[0][j - 1], prod);
        }
        for (int i = 1; i < m; ++i) {
            int prod = nums1[i] * nums2[0];
            dp[i][0] = Math.max(dp[i - 1][0], prod);
        }
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                int prod = nums1[i] * nums2[j];
                dp[i][j] = Math.max(prod + Math.max(dp[i - 1][j - 1], 0), Math.max(dp[i - 1][j], dp[i][j - 1]));
            }
        }
        return dp[m - 1][n - 1];
    }
}

public class Main {
    public static void main(String[] args) {
        int[] nums1 = {2,1,-2,5};
        int[] nums2 = {3,0,-6};
        int res = new Solution().maxDotProduct(nums1, nums2);
        System.out.println(res);
    }
}
