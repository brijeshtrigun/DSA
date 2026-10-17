class Solution {
public:
    int digitSum(int n) {
        int sum = 0;
        while (n > 0) {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }

    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<int> sortedNums = nums;

        // Sort by digit sum, then by value
        sort(sortedNums.begin(), sortedNums.end(), [&](int a, int b) {
            int sumA = digitSum(a);
            int sumB = digitSum(b);

            if (sumA == sumB)
                return a < b;

            return sumA < sumB;
        });

        // Map each number to its target index
        unordered_map<int, int> target;
        for (int i = 0; i < n; i++) {
            target[sortedNums[i]] = i;
        }

        vector<bool> visited(n, false);
        int swaps = 0;

        // Count permutation cycles
        for (int i = 0; i < n; i++) {
            if (visited[i] || target[nums[i]] == i)
                continue;

            int cycleLength = 0;
            int j = i;

            while (!visited[j]) {
                visited[j] = true;
                j = target[nums[j]];
                cycleLength++;
            }

            swaps += cycleLength - 1;
        }

        return swaps;
    }
};