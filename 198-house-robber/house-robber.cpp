class Solution {
public:
    int robber(vector<int>& nums, int idx , vector<int>& curr){
    

    if(idx>=nums.size()){
        return 0;
    }
    if(curr[idx]!=-1){
        return curr[idx];
    }
    int rob = nums[idx] + robber(nums , idx+2 , curr);
    int skip = robber(nums , idx+1 , curr);
    return curr[idx] = max(rob , skip);




    }
    int rob(vector<int>& nums) {
        vector<int> curr(nums.size()+1,-1);
      return  robber(nums , 0 , curr);
    }
};