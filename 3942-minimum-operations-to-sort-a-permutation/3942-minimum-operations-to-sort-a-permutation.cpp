 #include <vector>
#include <algorithm>

class Solution {
public:
    int minOperations(std::vector<int>& nums) {
        int n = nums.size();
        
        // Helper lambda to check if an array is a rotation of a given target sequence
        auto get_shift = [&](const std::vector<int>& target) {
            int shift = -1;
            for (int i = 0; i < n; ++i) {
                bool matches = true;
                for (int j = 0; j < n; ++j) {
                    if (nums[j] != target[(j + i) % n]) {
                        matches = false;
                        break;
                    }
                }
                if (matches) {
                    shift = i;
                    break;
                }
            }
            return shift;
        };

        // 1. Check if nums is a rotation of the increasing sequence [0, 1, ..., n-1]
        std::vector<int> increasing(n);
        for (int i = 0; i < n; ++i) increasing[i] = i;
        
        int inc_shift = get_shift(increasing);
        if (inc_shift != -1) {
            // Find where '0' is located in nums
            int pos_zero = 0;
            for (int i = 0; i < n; ++i) {
                if (nums[i] == 0) {
                    pos_zero = i;
                    break;
                }
            }
            // Option A: Rotate left `pos_zero` times to bring 0 to the front
            // Option B: Reverse (1) + rotate to position + Reverse (1)
            int cost1 = pos_zero;
            int cost2 = 2 + (n - pos_zero) % n;
            return std::min(cost1, cost2);
        }

        // 2. Check if nums is a rotation of the decreasing sequence [n-1, n-2, ..., 0]
        std::vector<int> decreasing(n);
        for (int i = 0; i < n; ++i) decreasing[i] = n - 1 - i;

        int dec_shift = get_shift(decreasing);
        if (dec_shift != -1) {
            // Find where `n-1` is located
            int pos_max = 0;
            for (int i = 0; i < n; ++i) {
                if (nums[i] == n - 1) {
                    pos_max = i;
                    break;
                }
            }
            // Option A: Reverse first (1) + rotate left
            // Option B: Rotate left first + Reverse (1)
            int cost1 = 1 + pos_max;
            int cost2 = (n - pos_max) % n + 1;
            return std::min(cost1, cost2);
        }

        // If neither, sorting is impossible
        return -1;
    }
};
  