// Refer to the leetcode solution for a simpler version
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;

class Interval {
    int start;
    int end;
    Interval(int st, int ed) {
        this.start = st;
        this.end = ed;
    }
}

class Cmp implements Comparator<Interval> {
    @Override
    public int compare(Interval a, Interval b) {
        if (a.start < b.start) {
            return -1;
        } else if (a.start == b.start) {
            if (a.end < b.end) {
                return -1;
            } else if (a.end == b.end) {
                return 0;
            } else {
                return 1;
            }
        } else {
            return 1;
        }
    }
}

class Solution {
    public int[][] merge(int[][] intervals) {
        int n = intervals.length;
        Interval[] intervalList = new Interval[n];
        for (int i = 0; i < intervals.length; ++i) {
            intervalList[i] = new Interval(intervals[i][0], intervals[i][1]);
        }
        Arrays.sort(intervalList, new Cmp());

        ArrayList<Interval> res = new ArrayList<>(); // LinkedList is better than ArrayList
        for (int i = 0; i < n; ++i) {
            if (i < n - 1 && intervalList[i].start == intervalList[i + 1].start) continue;
            if (res.isEmpty()) {
                res.add(intervalList[i]);
            } else {
                if (res.get(res.size() - 1).end < intervalList[i].start) {
                    res.add(intervalList[i]);
                } else {
                    Interval oldInt = res.get(res.size() - 1);
                    res.set(res.size() - 1, new Interval(oldInt.start, Math.max(intervalList[i].end, oldInt.end)));
                }
            }
        }

        int[][] result = new int[res.size()][2];
        for (int i = 0; i < res.size(); ++i) {
            result[i][0] = res.get(i).start;
            result[i][1] = res.get(i).end;
        }

        return result;
    }
}

public class Main {
    public static void main(String[] args) {
        int[][] intervals = {{1,3},{2,6},{8,10},{15,18}};
        int[][] res = new Solution().merge(intervals);
        for (int i = 0; i < res.length; ++i) {
            for (int j = 0; j < res[0].length; ++j) {
                System.out.printf("%d,", res[i][j]);
            }
            System.out.println();
        }
        System.out.println();
    }
}
