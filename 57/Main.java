import java.util.LinkedList;

class Solution {
    public int[][] insert(int[][] intervals, int[] newInterval) {
        int n = intervals.length;

        LinkedList<int[]> res = new LinkedList<>();
        if (n == 0) {
            res.add(newInterval);
            return res.toArray(new int[res.size()][]);
        }
        if (n == 1) {
            if (intervals[0][0] > newInterval[1] || intervals[0][1] < newInterval[0]) {
                if (intervals[0][0] < newInterval[0]) {
                    res.add(intervals[0]);
                    res.add(newInterval);
                } else {
                    res.add(newInterval);
                    res.add(intervals[0]);
                }
            } else {
                res.add(new int[]{Math.min(intervals[0][0], newInterval[0]), Math.max(intervals[0][1], newInterval[1])});
            }
            return res.toArray(new int[res.size()][]);
        }

        int l1 = 0, r1 = n - 1, mid = (l1 + r1) >> 1;
        while (r1 - l1 > 1) {
            if (newInterval[0] <= intervals[mid][1]) {
                r1 = mid;
            } else { // newInterval[0] > intervals[mid][1]
                l1 = mid;
            }
            mid = (l1 + r1) >> 1;
        }
        if (newInterval[0] <= intervals[0][1]) {
            l1 = -1; r1 = 0;
        } else if (newInterval[0] > intervals[n - 1][1]) {
            l1 = n - 1; r1 = n;
        }
        // intervals[l1][1] < newInterval[0] <= intervals[r1][1]
        int l2 = 0, r2 = n - 1; mid = (l2 + r2) >> 1;
        while (r2 - l2 > 1) {
            if (newInterval[1] < intervals[mid][0]) {
                r2 = mid;
            } else { // newInterval[1] >= intervals[mid][0]
                l2 = mid;
            }
            mid = (l2 + r2) >> 1;
        }
        if (newInterval[1] >= intervals[n - 1][0]) {
            l2 = n - 1; r2 = n;
        } else if (newInterval[1] < intervals[0][0]) {
            l2 = -1; r2 = 0;
        }
        System.out.printf("l1=%d, r1=%d, l2=%d, r2=%d\n", l1, r1, l2, r2);
        // intervals[l2][0] <= newInterval[1] < intervals[r2][0]

        if (r2 == 0) {
            res.add(newInterval);
        }
        for (int i = 0; i <= l1; ++i) {
            res.add(intervals[i]);
        }
        if (r2 - l1 > 1) {
            res.add(new int[]{Math.min(intervals[l1 + 1][0], newInterval[0]), Math.max(intervals[r2 - 1][1], newInterval[1])});
        } else if (l1 >= 0 && r2 < n) {
            res.add(newInterval);
        }
        for (int i = r2; i < n; ++i) {
            res.add(intervals[i]);
        }
        if (l1 == n - 1) {
            res.add(newInterval);
        }

        return res.toArray(new int[res.size()][]);
    }
}

public class Main {
    public static void main(String[] args) {
        int[][] intervals = {{3,5},{12,15}};
        int[] newInterval = {6,6};
        int[][] res = new Solution().insert(intervals, newInterval);
        for (int i = 0; i < res.length; ++i) {
            for (int j = 0; j < res[0].length; ++j) {
                System.out.printf("%d,", res[i][j]);
            }
            System.out.println();
        }
        System.out.println();
    }
}
