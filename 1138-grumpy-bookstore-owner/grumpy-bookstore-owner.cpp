class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size();
        int maxunsat = 0; 
        int currUnsat = 0;
        for(int i = 0; i < minutes; i++){
                maxunsat += customers[i]*grumpy[i];
        }
        int i = 0; 
        int j = minutes;
        currUnsat = maxunsat;
        while(j < n){
        currUnsat += customers[j] * grumpy[j];
        currUnsat -= customers[i] * grumpy[i];
        maxunsat = max(maxunsat, currUnsat);
        i++;
        j++;
        }
        int totalsat = maxunsat;
        for(int i = 0; i < n; i++){
            if(grumpy[i]== 0){
                totalsat += customers[i];
            }
        }
        return totalsat;
    }
};