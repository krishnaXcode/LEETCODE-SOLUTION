class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> free_servers;
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> busy_servers;
        
        for (int i = 0; i < servers.size(); ++i) {
            free_servers.push({servers[i], i});
        }
        
        vector<int> ans(tasks.size());
        long long current_time = 0;
        
        for (int j = 0; j < tasks.size(); ++j) {
            current_time = max(current_time, (long long)j);
            
            if (free_servers.empty() && busy_servers.top().first > current_time) {
                current_time = busy_servers.top().first;
            }
            
            while (!busy_servers.empty() && busy_servers.top().first <= current_time) {
                auto [free_time, idx] = busy_servers.top();
                busy_servers.pop();
                free_servers.push({servers[idx], idx});
            }
            
            auto [weight, idx] = free_servers.top();
            free_servers.pop();
            
            ans[j] = idx;
            busy_servers.push({current_time + tasks[j], idx});
        }
        
        return ans;
    }
};