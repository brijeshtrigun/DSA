class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int ans = 0;

        while (true) {
            bool sorted = true;

            for (int i = 1; i < nums.size(); i++) {
                if (nums[i - 1] > nums[i]) {
                    sorted = false;
                    break;
                }
            }

            if (sorted) return ans;

            // Find adjacent pair with minimum sum
            int idx = 0;

            for (int i = 1; i < nums.size() - 1; i++) {
                if (nums[i] + nums[i + 1] <
                    nums[idx] + nums[idx + 1]) {
                    idx = i;
                }
            }

            // Merge the pair
            nums[idx] = nums[idx] + nums[idx + 1];
            nums.erase(nums.begin() + idx + 1);

            ans++;
        }
    }
};