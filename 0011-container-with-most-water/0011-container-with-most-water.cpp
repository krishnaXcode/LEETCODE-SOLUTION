#include <vector>
#include <algorithm>
#include <iostream>

class Solution {
public:
    int maxArea(std::vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int max_water = 0;

        while (left < right) {
            // Calculate the width and the minimum height forming the container
            int width = right - left;
            int current_height = std::min(height[left], height[right]);
            
            // Calculate the current area and update max_water if it's larger
            int current_water = width * current_height;
            max_water = std::max(max_water, current_water);

            // Move the pointer pointing to the shorter line inward
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }

        return max_water;
    }
};