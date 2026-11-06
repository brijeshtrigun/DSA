class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {

        sort(logs.begin(), logs.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[1] < b[1];
             });

        int m = queries.size();

        vector<pair<int, int>> q;

        for (int i = 0; i < m; i++) {
            q.push_back({queries[i], i});
        }

        sort(q.begin(), q.end());

        vector<int> freq(n + 1, 0);
        vector<int> ans(m);

        int left = 0, right = 0;
        int active = 0;

        for (auto [t, idx] : q) {

            int start = t - x;

            // Include logs with time <= t
            while (right < logs.size() && logs[right][1] <= t) {
                int id = logs[right][0];

                if (freq[id] == 0)
                    active++;

                freq[id]++;
                right++;
            }

            // Remove logs with time < t - x
            while (left < right && logs[left][1] < start) {
                int id = logs[left][0];

                freq[id]--;

                if (freq[id] == 0)
                    active--;

                left++;
            }

            ans[idx] = n - active;
        }

        return ans;
    }
};