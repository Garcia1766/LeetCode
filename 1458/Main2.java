class Solution {
    private void printArr(int[][] arr) {
        for (int i = 0; i < arr.length; ++i) {
            for (int j = 0; j < arr[0].length; ++j) {
                System.out.printf("%d ", arr[i][j]);
            }
            System.out.println();
        }
    }

    public int maxDotProduct(int[] nums1, int[] nums2) {
        int m = nums1.length;
        int n = nums2.length;
        int[][] dp = new int[m + 1][n + 1];
        for (int j = 0; j <= n; ++j) {
            dp[0][j] = Integer.MIN_VALUE;
        }
        for (int i = 1; i <= m; ++i) {
            dp[i][0] = Integer.MIN_VALUE;
        }
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                int prod = nums1[i - 1] * nums2[j - 1];
                // Maximum of 4 terms: prod, prod + dp[i - 1][j - 1], dp[i - 1][j], and dp[i][j - 1]
                // There is no dp[i - 1][j - 1] because dp[i - 1][j - 1] <= dp[i - 1][j] and dp[i][j - 1]
                dp[i][j] = Math.max(prod + Math.max(dp[i - 1][j - 1], 0), Math.max(dp[i - 1][j], dp[i][j - 1]));
            }
        }
        printArr(dp);
        return dp[m][n];
    }
}

public class Main2 {
    public static void main(String[] args) {
        int[] nums1 = {2,1,-2,5};
        int[] nums2 = {3,0,-6};
        int res = new Solution().maxDotProduct(nums1, nums2);
        System.out.println(res);
    }
}
