class Solution {
public:
    int maxProfit(vector<int>& prices) {
     int n = prices.size();
      int totalprofit = 0;
      int start = 0;
      int next = 1;
      while(next <= n -1){
        if(prices[start] < prices[next]){
            int profit = prices[next] - prices[start];
            totalprofit += profit;
        }
            start++;
            next++;
        
    }
      return totalprofit;

    }
};