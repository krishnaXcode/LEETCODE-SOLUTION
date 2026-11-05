 #include <vector>
#include <algorithm>
#include <cmath>

class Solution {
public:
    int findTheDistanceValue(std::vector<int>& arr1, std::vector<int>& arr2, int d) {
        std::sort(arr2.begin(), arr2.end());
        int count = 0;
        
        for (int x : arr1) {
            auto it = std::lower_bound(arr2.begin(), arr2.end(), x);
            bool isValid = true;
            
            if (it != arr2.end()) {
                if (std::abs(*it - x) <= d) isValid = false;
            }
            if (it != arr2.begin()) {
                if (std::abs(*(it - 1) - x) <= d) isValid = false;
            }
            
            if (isValid) {
                count++;
            }
        }
        
        return count;
    }
};
    