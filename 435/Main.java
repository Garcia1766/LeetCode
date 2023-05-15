import java.util.Arrays;
import java.util.Comparator;

class Solution {
    public int eraseOverlapIntervals(int[][] intervals) {
        Arrays.sort(intervals, new Comparator<int[]>() {
            public int compare(int[] a, int[] b) {
                return a[1] - b[1];
            }
        });
        int res = 1;
        int pre = 0;
        for  (int i = 1; i < intervals.length; ++i) {
            if (intervals[i][0] >= intervals[pre][1]) {
                ++res;
                pre = i;
            }
        }
        return intervals.length - res;
    }
}

public class Main {
    public static void main(String[] args) {
        int[][] intervals = {{1,2},{2,3},{3,4},{1,3}};
        int res = new Solution().eraseOverlapIntervals(intervals);
        System.out.println(res);
    }
}
