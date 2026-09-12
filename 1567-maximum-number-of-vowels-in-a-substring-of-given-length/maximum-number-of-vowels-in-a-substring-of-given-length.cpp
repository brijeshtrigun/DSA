class Solution {
public :
     bool isvowel(char ch){
       if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'){
            return true;
        }
        else{
            return false;
        }

     }
    
    int maxVowels(string s, int k) {
        int n = s.length();
        int maxlen  = 0;
        int count = 0;
        for(int i  = 0; i <k ; i++){
            char ch = s[i];
            if(isvowel(ch)){
                count++;
            }
        }
        maxlen = max(maxlen, count);
        for(int i = k;  i <n; i++){
            if(isvowel(s[i])){
                count++;
            }
            if(isvowel(s[i -k])){
                count--;
            }
            maxlen = max(maxlen, count);
        }
        return maxlen;
    }
};