class Solution {
public:
    int divide(int dividend, int divisor) {
        bool sign = true;
        if(dividend == divisor) return 1;
        if(dividend < 0 && divisor > 0) sign = false;
        if(dividend > 0 && divisor < 0) sign = false;
        long long n = abs((long long)dividend);
        long long d = abs((long long)divisor);
        long long ans = 0;
        while(n >= d){
            int count = 0;
            while( n >= (d << (count +1))){
                  count++;
            }
                  ans+= (1LL << count);
                  n = n - (d << count);  
        }       
            
            if(ans >= (1LL << 31) && sign == true)
            return INT_MAX;
            if(ans >= (1LL << 31) && sign == false)
            return INT_MIN;
        
        return sign ? ans : -ans; 
    }
};