import java.util.Arrays;

class Solution {
    public long minSumSquareDiff(int[] nums1, int[] nums2, int k1, int k2) {
        int n = nums1.length;
        long totalOps = (long) k1 + k2;
        
        // Find the maximum difference to size our frequency bucket array
        int maxDiff = 0;
        int[] diffs = new int[n];
        for (int i = 0; i < n; i++) {
            diffs[i] = Math.abs(nums1[i] - nums2[i]);
            if (diffs[i] > maxDiff) {
                maxDiff = diffs[i];
            }
        }
        
        // Count frequencies of each difference
        int[] count = new int[maxDiff + 1];
        for (int d : diffs) {
            count[d]++;
        }
        
        // Greedily reduce differences from maxDiff down to 1
        for (int d = maxDiff; d > 0 && totalOps > 0; d--) {
            if (count[d] == 0) continue;
            
            // Operations needed to reduce all elements with difference `d` to `d - 1`
            long opsToReduce = Math.min(totalOps, count[d]);
            totalOps -= opsToReduce;
            count[d] -= opsToReduce;
            count[d - 1] += opsToReduce;
        }
        
        // Calculate the final minimum sum of squared differences
        long minSumSquares = 0;
        for (int d = 1; d <= maxDiff; d++) {
            if (count[d] > 0) {
                minSumSquares += (long) count[d] * d * d;
            }
        }
        
        return minSumSquares;
    }
}