class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        
        int n = nums.size();
        int k1 = k;
        for(int i = 0; i < n; i++){
            if(nums[i] == k1){
                k1 += k;

            }
            else if(nums[i] < k1){
                continue;
            }
            else{
                return k1;
            }
            
        }
        return k1;
        
    }
};