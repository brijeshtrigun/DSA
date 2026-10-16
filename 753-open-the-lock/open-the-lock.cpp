class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> dead(deadends.begin(), deadends.end());
        unordered_set<string> visited;

        string start = "0000";

        if (dead.count(start)) return -1;
        if (target == start) return 0;

        queue<pair<string, int>> q;
        q.push({start, 0});
        visited.insert(start);

        while (!q.empty()) {
            auto [curr, steps] = q.front();
            q.pop();

            if (curr == target) return steps;

            for (int i = 0; i < 4; i++) {
                string next = curr;

                // Turn digit up
                next[i] = (curr[i] == '9') ? '0' : curr[i] + 1;

                if (!dead.count(next) && !visited.count(next)) {
                    visited.insert(next);
                    q.push({next, steps + 1});
                }

                // Turn digit down
                next = curr;
                next[i] = (curr[i] == '0') ? '9' : curr[i] - 1;

                if (!dead.count(next) && !visited.count(next)) {
                    visited.insert(next);
                    q.push({next, steps + 1});
                }
            }
        }

        return -1;
    }
};