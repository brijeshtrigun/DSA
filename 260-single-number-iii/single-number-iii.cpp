class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xorVal = 0;
        for(int num : nums){
            xorVal ^= num;
        }
        int diff_bit = 1;

        while((xorVal & diff_bit) == 0){
            diff_bit <<= 1;
        }
        int a = 0, b =0;
        for(int num : nums){
            if(diff_bit & num){
                a = a^num;
            }
            else{
                b = b^num;
            }
        }
        return {a, b};
    }
};