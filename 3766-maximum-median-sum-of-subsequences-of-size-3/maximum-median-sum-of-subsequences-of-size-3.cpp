class Solution {
public:
    long long maximumMedianSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
         int i = 0; 
         int n = nums.size();
         int j = n -1;
         long long sum = 0;
         while(i < j){
            long long median = nums[j-1];
            sum += median;
            i++;
            j = j-2;
         }
         
         return sum;
    }
};