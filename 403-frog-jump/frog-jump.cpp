class Solution {
public:
    int n;
    unordered_map<int, int> mp;
    int t[2001][2001];
    int solve(vector<int>& stones, int prevjump, int currIndex){
        if(currIndex == n-1) return true;
        if(t[currIndex][prevjump] != -1){
            return t[currIndex][prevjump];
        }
        bool result = false;
        for(int nextjump = prevjump -1; nextjump <= prevjump+1; nextjump++){
            if(nextjump > 0){
                int nextstone = stones[currIndex] + nextjump;
                if(mp.find(nextstone) != mp.end()){
                    result = result || solve(stones, nextjump, mp[nextstone]);
                }
            }
        }
        return t[currIndex][prevjump] =  result;
    }

    bool canCross(vector<int>& stones) {
      n = stones.size();
      if(n==1) return true;
      if(stones[1] != 1) return false; 
      mp.clear();
      for(int i =0; i < n; i++){
        mp[stones[i]] = i;
      }
      memset(t, -1, sizeof(t));
      return solve(stones, 0, 0);
    }
};