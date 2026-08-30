class Solution {
public:
    int maximumLength(string s) {
        int n = s.size();
        vector<vector<int>> runs(26);

        // Store lengths of consecutive runs
        for (int i = 0; i < n; ) {
            int j = i;

            while (j < n && s[j] == s[i])
                j++;

            runs[s[i] - 'a'].push_back(j - i);
            i = j;
        }

        int ans = -1;

        // Try every possible substring length
        for (int len = 1; len <= n; len++) {
            for (int c = 0; c < 26; c++) {
                int count = 0;

                for (int L : runs[c]) {
                    if (L >= len)
                        count += L - len + 1;
                }

                if (count >= 3)
                    ans = len;
            }
        }

        return ans;
    }
};