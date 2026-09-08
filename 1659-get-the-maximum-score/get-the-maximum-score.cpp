class Solution {
public:
    int maxSum(vector<int>& nums1, vector<int>& nums2) {
         const long long MOD = 1000000007;
       long long s1 = 0;
       long long s2 = 0;
       int n = nums1.size();
       int m = nums2.size();
       long long res = 0;
       int i = 0, j = 0;
       while(i < n && j < m){
        if(nums1[i] < nums2[j]){
            s1 +=  nums1[i];
            i++;
        }
        else if(nums2[j] < nums1[i]){
            s2 += nums2[j];
            j++;
        }
        else
        {
            res += max(s1, s2) + nums1[i];
            s1 = 0;
            s2 = 0;
             i++;
            j++;
        }
       }
        while(i < n){
            s1 += nums1[i];
            i++;
        }
        while(j < m){
            s2 += nums2[j];
            j++;
        }

       res += max(s1, s2);
       return res % MOD;
    }
};