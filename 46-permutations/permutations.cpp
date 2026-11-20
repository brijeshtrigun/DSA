
class Solution {
public:
    void solve(vector<int>& nums, int idx, vector<vector<int>>& ans) {
        // Base case: one permutation is complete
        if (idx == nums.size()) {
            ans.push_back(nums);
            return;
        }

        for (int i = idx; i < nums.size(); i++) {
            // Choose
            swap(nums[idx], nums[i]);

            // Explore
            solve(nums, idx + 1, ans);

            // Undo the choice (backtrack)
            swap(nums[idx], nums[i]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        solve(nums, 0, ans);
        return ans;
    }
};
