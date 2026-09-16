class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.length();
        int m = t.length();
        if( m > n){
            return "";
        }
        int count = 0;
        int minlen = INT_MAX;
        int l = 0; 
        int r = 0;
        int startIndex = 0;
        unordered_map<char, int> mp;
        for(int i = 0; i < m; i++){
            mp[t[i]]++;
        }
        while(r < n){
            if(mp[s[r]] > 0){
                count++;
            }
             mp[s[r]]--;
            while(count == m){
            if(r - l +1 < minlen){
                minlen = r-l+1;
                startIndex = l;
            }
            mp[s[l]]++;
            if(mp[s[l]] > 0){
                count--;
            }
            l++;
            }
            r++;
        }
        if(minlen == INT_MAX) return "";
        return s.substr(startIndex, minlen);
        }
};