import java.util.Arrays;

class Bucket {
    boolean used;
    int minval;
    int maxval;

    Bucket() {
        this.used = false;
        this.minval = Integer.MAX_VALUE;
        this.maxval = Integer.MIN_VALUE;
    }
}

class Solution {
    public int maximumGap(int[] nums) {
        int n = nums.length;
        if (n <= 1) return 0;

        int maxVal = Arrays.stream(nums).max().getAsInt();
        int minVal = Arrays.stream(nums).min().getAsInt();
        int bucketSize = Math.max(1, (maxVal - minVal) / (n - 1));
        int bucketNum = (maxVal - minVal) / bucketSize + 1;

        Bucket[] buckets = new Bucket[bucketNum];
        for (int i = 0; i < buckets.length; ++i) {
            buckets[i] = new Bucket();
        }

        for (int i = 0; i < n; ++i) {
            int bucketIdx = (nums[i] - minVal) / bucketSize;
            buckets[bucketIdx].used = true;
            buckets[bucketIdx].minval = Math.min(nums[i], buckets[bucketIdx].minval);
            buckets[bucketIdx].maxval = Math.max(nums[i], buckets[bucketIdx].maxval);
        }

        int maxGap = 0, prevBucketMax = minVal;
        for (Bucket bucket : buckets) {
            if (bucket.used) {
                maxGap = Math.max(maxGap, bucket.minval - prevBucketMax);
                prevBucketMax = bucket.maxval;
            }
        }

        return maxGap;
    }
}

public class Main {
    public static void main(String[] args) {
        int[] nums = {3,6,9,1};
        int res = new Solution().maximumGap(nums);
        System.out.println(res);
    }
}
