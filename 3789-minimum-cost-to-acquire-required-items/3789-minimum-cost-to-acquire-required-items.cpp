 #include <algorithm>

class Solution {
public:
    long long minimumCost(long long cost1, long long cost2, long long costBoth, long long need1, long long need2) {
        long long min_common = std::min(need1, need2);
        long long total_cost = min_common * std::min(costBoth, cost1 + cost2);
        
        need1 -= min_common;
        need2 -= min_common;
        
        if (need1 > 0) {
            total_cost += need1 * std::min(costBoth, cost1);
        } else if (need2 > 0) {
            total_cost += need2 * std::min(costBoth, cost2);
        }
        
        return total_cost;
    }
};