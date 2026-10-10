
class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2,
                               int k1, int k2) {
        long long k = (long long)k1 + k2;
        int n = nums1.size();

        vector<long long> diff(n);
        long long mx = 0, sum = 0;

        for (int i = 0; i < n; i++) {
            diff[i] = abs(nums1[i] - nums2[i]);
            mx = max(mx, diff[i]);
            sum += diff[i];
        }

        if (sum <= k) return 0;

        // Find the minimum maximum difference L
        // such that reducing all differences to L
        // requires at most k operations.
        long long lo = 0, hi = mx;

        while (lo < hi) {
            long long mid = lo + (hi - lo) / 2;
            long long need = 0;

            for (long long d : diff) {
                if (d > mid) {
                    need += d - mid;
                }
                if (need > k) break;
            }

            if (need <= k)
                hi = mid;
            else
                lo = mid + 1;
        }

        long long L = lo;
        long long used = 0;
        long long ans = 0;

        for (long long &d : diff) {
            if (d > L) {
                used += d - L;
                d = L;
            }
            ans += d * d;
        }

        // Use leftover operations to reduce some L's to L-1.
        long long rem = k - used;

        for (long long d : diff) {
            if (rem == 0) break;

            if (d == L && L > 0) {
                ans -= L * L;
                ans += (L - 1) * (L - 1);
                rem--;
            }
        }

        return ans;
    }
};
