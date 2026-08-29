class Solution {
public:
    bool checkIfPangram(string sentence) {
       vector <int> freq(26, 0);
       for(char ch: sentence){
        int index = ch - 'a';
        freq[index]++;
       } 
       for(int &count : freq){
        if(count == 0)
        return false;
       }
       return true;
    }
};