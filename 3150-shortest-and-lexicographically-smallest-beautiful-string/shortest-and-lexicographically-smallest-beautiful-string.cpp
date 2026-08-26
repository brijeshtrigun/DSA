class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();

        int left = 0;
        int ones = 0;

        int bestL = -1;
        int bestR = -1;

        for (int right = 0; right < n; right++) {

            if (s[right] == '1')
                ones++;

            // We need exactly k ones
            while (ones > k) {
                if (s[left] == '1')
                    ones--;
                left++;
            }

            // Window has exactly k ones
            if (ones == k) {

                // Remove leading zeroes.
                // This makes the window as short as possible.
                while (s[left] == '0')
                    left++;

                // Compare with the best answer
                if (bestL == -1 ||
                    right - left < bestR - bestL ||
                    (right - left == bestR - bestL &&
                     s.compare(left, right - left + 1,
                               s, bestL, bestR - bestL + 1) < 0)) {

                    bestL = left;
                    bestR = right;
                }
            }
        }

        if (bestL == -1)
            return "";

        return s.substr(bestL, bestR - bestL + 1);
    }
};