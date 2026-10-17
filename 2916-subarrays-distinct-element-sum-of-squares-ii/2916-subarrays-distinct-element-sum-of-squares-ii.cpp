#include <vector>

using namespace std;

class Solution {
    static const int MOD = 1e9 + 7;
    int n;
    vector<long long> sumSq, sumLinear, lazy;

    void push(int node, int l, int r) {
        if (lazy[node] != 0) {
            int mid = (l + r) / 2;
            apply(2 * node, l, mid, lazy[node]);
            apply(2 * node + 1, mid + 1, r, lazy[node]);
            lazy[node] = 0;
        }
    }

    void apply(int node, int l, int r, long long val) {
        long long len = r - l + 1;
        // sumSq' = sumSq + 2*val*sumLinear + val*val*len
        sumSq[node] = (sumSq[node] + 2 * val % MOD * sumLinear[node] % MOD + val * val % MOD * len) % MOD;
        // sumLinear' = sumLinear + val*len
        sumLinear[node] = (sumLinear[node] + val * len) % MOD;
        lazy[node] = (lazy[node] + val) % MOD;
    }

    void update(int node, int l, int r, int ql, int qr, long long val) {
        if (ql > r || qr < l) return;
        if (ql <= l && r <= qr) {
            apply(node, l, r, val);
            return;
        }
        push(node, l, r);
        int mid = (l + r) / 2;
        update(2 * node, l, mid, ql, qr, val);
        update(2 * node + 1, mid + 1, r, ql, qr, val);
        sumSq[node] = (sumSq[2 * node] + sumSq[2 * node + 1]) % MOD;
        sumLinear[node] = (sumLinear[2 * node] + sumLinear[2 * node + 1]) % MOD;
    }

public:
    int sumCounts(vector<int>& nums) {
        n = nums.size();
        sumSq.assign(4 * n, 0);
        sumLinear.assign(4 * n, 0);
        lazy.assign(4 * n, 0);
        
        vector<int> last_pos(100005, -1); // values ki max range ke mutabiq ya phir unordered_map use kar lo
        // Agar values badi hain toh unordered_map<int, int> last_pos use kar lena.
        
        long long total_sum = 0;
        unordered_map<int, int> mp;
        
        for (int j = 0; j < n; ++j) {
            int prev = mp.count(nums[j]) ? mp[nums[j]] + 1 : 0;
            mp[nums[j]] = j;
            
            update(1, 0, n - 1, prev, j, 1);
            total_sum = (total_sum + sumSq[1]) % MOD;
        }
        
        return total_sum;
    }
};