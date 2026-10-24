#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
        std::vector<std::vector<int>> result;
        int n = nums.size();
        
        // Step 1: Sort the array
        std::sort(nums.begin(), nums.end());
        
        // Step 2: Fix one number at a time
        for (int i = 0; i < n - 2; ++i) {
            // Optimization: If the smallest number is positive, sum cannot be zero
            if (nums[i] > 0) break;
            
            // Skip duplicates for the anchor element
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            
            // Step 3: Two-pointer approach for the remaining part
            int left = i + 1;
            int right = n - 1;
            
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                
                if (sum == 0) {
                    result.push_back({nums[i], nums[left], nums[right]});
                    
                    // Skip duplicates for left and right pointers
                    while (left < right && nums[left] == nums[left + 1]) left++;
                    while (left < right && nums[right] == nums[right - 1]) right--;
                    
                    left++;
                    right--;
                } else if (sum < 0) {
                    left++;
                } else {
                    right--;
                }
            }
        }
        
        return result;
    }
};