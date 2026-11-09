class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> busy;
        set<int> available;
        for (int i = 0; i < k; ++i) {
            available.insert(i);
        }

        vector<int> count(k, 0);
        int max_handled = 0;

        for (int i = 0; i < arrival.size(); ++i) {
            long long start = arrival[i];
            long long duration = load[i];

            while (!busy.empty() && busy.top().first <= start) {
                available.insert(busy.top().second);
                busy.pop();
            }

            if (available.empty()) {
                continue;
            }

            auto it = available.lower_bound(i % k);
            if (it == available.end()) {
                it = available.begin();
            }

            int server_id = *it;
            available.erase(it);

            busy.push({start + duration, server_id});
            count[server_id]++;
            max_handled = max(max_handled, count[server_id]);
        }

        vector<int> result;
        for (int i = 0; i < k; ++i) {
            if (count[i] == max_handled) {
                result.push_back(i);
            }
        }

        return result;
    }
};
