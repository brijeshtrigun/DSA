class Solution {
public:
      int findDays(vector<int>& weights, int cap){
        int d = 1, load = 0;
        for(int i = 0; i< weights.size(); i++){
            if(weights[i] + load > cap){
                d++;
                load = weights[i];
            }else{
                load += weights[i];
            }

        }
        return d;
      }
    int shipWithinDays(vector<int>& weights, int days) {
        int sum = 0;
        int n = weights.size();
        for(int i = 0; i< n; i++){
            sum += weights[i];
        }
        int maxi = 0;
        for(int i = 0; i < n; i++){
            if(weights[i] > maxi){
                maxi = weights[i];
            }
        }
        int low = maxi;
        int high = sum;
        while(low  <= high){
            int mid = low +(high - low)/2;
            int numberofdays = findDays(weights, mid);
                if(numberofdays <= days){
                    high = mid -1;
            }
            else{
                low = mid +1;
            }
        }
        return low;
    }
};