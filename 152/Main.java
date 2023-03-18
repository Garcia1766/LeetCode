import java.util.Arrays;

class Solution {
    private int[] numArray;

    private int getMaxProduct(int left, int right) {
        if (left >= right) return 1;
        if (right - left == 1) return numArray[left];

        int mid = (left + right) / 2;
        int maxLeftProd = 1;
        int minLeftProd = 1;
        int maxRightProd = 1;
        int minRightProd = 1;
        int curHalfProd = 1;
        int combinedRes = 1;
        if (numArray[mid] == 0) {
            combinedRes = 0;
        } else {
            for (int i = mid - 1; i >= left; --i) {
                curHalfProd *= numArray[i];
                maxLeftProd = Math.max(maxLeftProd, curHalfProd);
                minLeftProd = Math.min(minLeftProd, curHalfProd);
            }
            curHalfProd = 1;
            for (int i = mid + 1; i < right; ++i) {
                curHalfProd *= numArray[i];
                maxRightProd = Math.max(maxRightProd, curHalfProd);
                minRightProd = Math.min(minRightProd, curHalfProd);
            }
            int[] candidates = {numArray[mid] * maxLeftProd, numArray[mid] * minLeftProd, numArray[mid] * maxRightProd, numArray[mid] * minRightProd,
                numArray[mid] * maxLeftProd * maxRightProd, numArray[mid] * maxLeftProd * minRightProd,
                numArray[mid] * minLeftProd * maxRightProd, numArray[mid] * minLeftProd * minRightProd};
            combinedRes = Arrays.stream(candidates).max().getAsInt();
        }

        int leftRes = getMaxProduct(left, mid);
        int rightRes = getMaxProduct(mid, right);

        return Math.max(combinedRes, Math.max(leftRes, rightRes));
    }

    public int maxProduct(int[] nums) {
        this.numArray = nums;
        return getMaxProduct(0, nums.length);
    }
}

public class Main {
    public static void main(String[] args) {
        int[] nums = {-2,3,-4};
        int res = new Solution().maxProduct(nums);
        System.out.println(res);
    }
}
