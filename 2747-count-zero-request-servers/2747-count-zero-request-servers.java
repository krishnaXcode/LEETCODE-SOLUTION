import java.util.Arrays;

class Solution {
    public int[] countServers(int n, int[][] logs, int x, int[] queries) {
        int m = queries.length;
        int[][] sortedQueries = new int[m][2];
        for (int i = 0; i < m; i++) {
            sortedQueries[i][0] = queries[i];
            sortedQueries[i][1] = i;
        }

        // Sort queries by time
        Arrays.sort(sortedQueries, (a, b) -> Integer.compare(a[0], b[0]));
        // Sort logs by time
        Arrays.sort(logs, (a, b) -> Integer.compare(a[1], b[1]));

        int[] ans = new int[m];
        int[] serverCount = new int[n + 1];
        int activeServers = 0;
        int left = 0, right = 0;
        int numLogs = logs.length;

        for (int i = 0; i < m; i++) {
            int qTime = sortedQueries[i][0];
            int qIndex = sortedQueries[i][1];
            int windowStart = qTime - x;
            int windowEnd = qTime;

            // Add logs whose time <= windowEnd
            while (right < numLogs && logs[right][1] <= windowEnd) {
                int serverId = logs[right][0];
                if (serverCount[serverId] == 0) {
                    activeServers++;
                }
                serverCount[serverId]++;
                right++;
            }

            // Remove logs whose time < windowStart
            while (left < numLogs && logs[left][1] < windowStart) {
                int serverId = logs[left][0];
                serverCount[serverId]--;
                if (serverCount[serverId] == 0) {
                    activeServers--;
                }
                left++;
            }

            // Servers with zero requests = total servers - active servers in window
            ans[qIndex] = n - activeServers;
        }

        return ans;
    }
}