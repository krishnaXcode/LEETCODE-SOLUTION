class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = static_cast<int>(nums.size());
        int ans = 1;
        long long max_lcm = 2520;

        for (int i = 0; i < n; ++i) {
            long long prod = 1;
            long long g = 0;
            long long l = 1;

            for (int j = i; j < n; ++j) {
                long long x = nums[j];
                if (prod > max_lcm * max_lcm * max_lcm) {
                    break;
                }
                prod *= x;
                g = (g == 0) ? x : std::gcd(g, x);
                l = std::lcm(l, x);

                if (prod == g * l) {
                    ans = max(ans, j - i + 1);
                }
            }
        }

        return ans;
    }
};