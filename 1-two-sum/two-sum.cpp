class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
     unordered_map <int, int> mpp;
     int n = nums.size();
     for(int i = 0; i < n; i ++){
        int first = nums[i];
        int moreneeded = target - nums[i];
        if(mpp.find(moreneeded) != mpp.end()){
        return {mpp[moreneeded], i};
     }
     mpp[first] = i;
     }
     return {-1, -1};
    }
};