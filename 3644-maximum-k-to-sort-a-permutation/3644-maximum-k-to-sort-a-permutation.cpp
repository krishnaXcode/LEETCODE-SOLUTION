#include <vector>

class Solution {
public:
    int sortPermutation(std::vector<int>& nums) {
        int n = nums.size();
        int k_star = -1; // Represents all bits initially set to 1
        
        for (int i = 0; i < n; ++i) {
            // If the element is not in its correct position
            if (nums[i] != i) {
                if (k_star == -1) {
                    k_star = nums[i];
                } else {
                    k_star &= nums[i];
                }
            }
        }
        
        // If the array is already sorted, no swaps are needed, return 0
        return (k_star == -1) ? 0 : k_star;
    }
};