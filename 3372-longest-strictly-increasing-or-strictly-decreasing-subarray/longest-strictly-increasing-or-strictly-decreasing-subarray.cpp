class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        int incCount = 1;
        int decCount = 1;
        int ans = 1;
        for(int i =0; i < n-1; i++){
            if(nums[i] < nums[i+1]){
                incCount++;
                decCount = 1;
            }
            else if(nums[i] > nums[i+1]){
                decCount++;
                incCount = 1;
            }
            else{
                incCount = 1;
                decCount = 1;
            }
                 ans = max(ans, max(incCount, decCount));
        }
        return ans;
    }
};