#include <vector>
#include <algorithm>

class Solution {
public:
    long long sortableIntegers(std::vector<int>& nums) {
        int n = nums.size();
        
        // prefMax[i] stores the maximum value in nums[0...i-1]
        std::vector<int> prefMax(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            prefMax[i + 1] = std::max(prefMax[i], nums[i]);
        }
        
        // suffMin[i] stores the minimum value in nums[i...n-1]
        std::vector<int> suffMin(n + 1, 1e9);
        for (int i = n - 1; i >= 0; --i) {
            suffMin[i] = std::min(nums[i], suffMin[i + 1]);
        }
        
        // prefDrop[i] counts the number of adjacent drops up to index i
        std::vector<int> prefDrop(n, 0);
        for (int i = 1; i < n; ++i) {
            prefDrop[i] = prefDrop[i - 1] + (nums[i - 1] > nums[i] ? 1 : 0);
        }
        
        auto check = [&](int k) {
            for (int start = 0; start < n; start += k) {
                int end = start + k - 1;
                
                // Count descents inside the current block of length k
                int drops = prefDrop[end] - prefDrop[start];
                if (nums[end] > nums[start]) {
                    ++drops;
                }
                
                if (drops > 1 || prefMax[start] > suffMin[start]) {
                    return false;
                }
            }
            return true;
        };
        
        long long total_sum = 0;
        for (int k = 1; k * k <= n; ++k) {
            if (n % k == 0) {
                if (check(k)) {
                    total_sum += k;
                }
                int other = n / k;
                if (other != k && (n % other == 0)) {
                    if (check(other)) {
                        total_sum += other;
                    }
                }
            }
        }
        
        return total_sum;
    }
};