import java.util.List;

class Solution {
    public int maxSum(List<Integer> nums, int k) {
        int[] bitCounts = new int[32];
        for (int num : nums) {
            for (int i = 0; i < 32; i++) {
                if ((num & (1 << i)) != 0) {
                    bitCounts[i]++;
                }
            }
        }

        long[] maxNums = new long[k];
        for (int i = 0; i < 32; i++) {
            for (int j = 0; j < k; j++) {
                if (bitCounts[i] > 0) {
                    maxNums[j] |= (1L << i);
                    bitCounts[i]--;
                }
            }
        }

        long mod = 1000000007;
        long totalSum = 0;
        for (int i = 0; i < k; i++) {
            totalSum = (totalSum + (maxNums[i] * maxNums[i]) % mod) % mod;
        }

        return (int) totalSum;
    }
}