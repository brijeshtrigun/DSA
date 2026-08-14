class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
       int i, j = 0;
       int sum = 0;
       int n= nums.size();
        unordered_map<int, int> mp;
        mp[0] = -1;
        for(int i = 0; i < n; i++){
            sum += nums[i];
            int reaminder = sum%k;
            if(mp.find(reaminder) != mp.end()){
                if(i - mp[reaminder] >= 2){

                
                return true;
                }
            }
            else {
                mp[reaminder] = i;
            }
        }
       return false; 

    }
};