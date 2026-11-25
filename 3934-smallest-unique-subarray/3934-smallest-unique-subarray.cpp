class Solution {
public:
    int smallestUniqueSubarray(vector<int>& nums) {
        int n = static_cast<int>(nums.size());
        const long long BASE = 100003LL;
        const long long MOD1 = 1000000007LL;
        const long long MOD2 = 1000000009LL;

        vector<long long> p1(n + 1, 1), p2(n + 1, 1);
        vector<long long> h1(n + 1, 0), h2(n + 1, 0);

        for (int i = 0; i < n; ++i) {
            long long val = nums[i];
            p1[i + 1] = (p1[i] * BASE) % MOD1;
            p2[i + 1] = (p2[i] * BASE) % MOD2;
            h1[i + 1] = (h1[i] * BASE + val) % MOD1;
            h2[i + 1] = (h2[i] * BASE + val) % MOD2;
        }

        auto getHash = [&](int l, int r) -> unsigned long long {
            long long x1 = (h1[r + 1] - h1[l] * p1[r - l + 1]) % MOD1;
            if (x1 < 0) x1 += MOD1;
            long long x2 = (h2[r + 1] - h2[l] * p2[r - l + 1]) % MOD2;
            if (x2 < 0) x2 += MOD2;
            return (static_cast<unsigned long long>(x1) << 32) | static_cast<unsigned long long>(x2);
        };

        auto hasUnique = [&](int len) -> bool {
            unordered_map<unsigned long long, int> freq;
            freq.reserve(n - len + 1);
            for (int i = 0; i + len <= n; ++i) {
                ++freq[getHash(i, i + len - 1)];
            }
            for (const auto& [_, cnt] : freq) {
                if (cnt == 1) return true;
            }
            return false;
        };

        int low = 1, high = n;
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (hasUnique(mid)) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};