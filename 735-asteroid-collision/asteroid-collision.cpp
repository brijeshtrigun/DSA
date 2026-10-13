class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        vector<int> ans;
        stack<int> st;
        bool flag=true;
        for(int i = 0; i  < n; i++){
            flag=true;
            while(!st.empty() && st.top() > 0 && asteroids[i] < 0){
            int sum = asteroids[i] + st.top();
            if(sum  < 0){
                st.pop();
                flag=true;
            }
            else if(sum == 0){
                st.pop();
                asteroids[i]=0;
                flag = false;
            }
            else{
             flag=false;
             break;
            }
            }
            if(flag)
            st.push(asteroids[i]);
            
              
        }
        stack<int> s2;
        while(!st.empty()){
            s2.push(st.top());
            st.pop();

        }
        while(!s2.empty()){
            ans.push_back(s2.top());
            s2.pop();
        }
        return ans;
    }
};