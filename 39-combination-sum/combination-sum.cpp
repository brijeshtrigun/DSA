class Solution {
public:
    void combSum(vector<int>& candidates, int index, int target,
                 vector<int>& temp, vector<vector<int>>& result) {

        if (target == 0) {
            result.push_back(temp);
            return;
        }

        if (index == candidates.size() || target < 0)
            return;

        // include current element
        if (target >= candidates[index]) {
            temp.push_back(candidates[index]);
            combSum(candidates, index, target - candidates[index], temp, result);
            temp.pop_back();
        }

        // exclude current element
        combSum(candidates, index + 1, target, temp, result);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> temp;

        combSum(candidates, 0, target, temp, result);

        return result;
    }
};