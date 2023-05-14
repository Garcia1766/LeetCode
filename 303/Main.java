class NumArray {
    private int[] sumFrom;

    public NumArray(int[] nums) {
        int n = nums.length;
        sumFrom = new int[n + 1];
        for (int i = n - 1; i >= 0; --i) {
            sumFrom[i] = nums[i] + sumFrom[i + 1];
        }
    }
    
    public int sumRange(int left, int right) {
        return sumFrom[left] - sumFrom[right + 1];
    }
}

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(left,right);
 */

public class Main {
    public static void main(String[] args) {
        int[] array = {-2, 0, 3, -5, 2, -1};
        NumArray numArray = new NumArray(array);
        int res = numArray.sumRange(0, 2); // return (-2) + 0 + 3 = 1
        System.out.println(res);
        res = numArray.sumRange(2, 5); // return 3 + (-5) + 2 + (-1) = -1
        System.out.println(res);
        res = numArray.sumRange(0, 5); // return (-2) + 0 + 3 + (-5) + 2 + (-1) = -3
        System.out.println(res);
    }
}
