class Solution {
public:
    int maxArea(vector<int>& height) {
      int n = height.size();
      int left = 0; 
      int right = n-1;
      int heightmax = height[0];
      int maxwater =  0;
      int water = 0;
      while(left  < right){
        int width = right - left;
        heightmax = min(height[left], height[right]);
        water = width * heightmax;
        maxwater = max(water, maxwater); 
      
      if(height[left] < height[right]){
        left++;
      }
      else{
        right--;
      }
      }
      return maxwater;

    }
};