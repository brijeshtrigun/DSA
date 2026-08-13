class Solution {
public:
    int maxArea(vector<int>& height) {
       int n = height.size();

        int left = 0, right = n- 1;;
        int width = right - left;
        int max_area = 0;
       while(left < right){
        int max_height = min(height[left], height[right]);
        width=right-left;
        int area = width * max_height;
        max_area = max(area, max_area);
        if(height[left] < height[right]){
            left++;
        }else{
            right--;
        }
       }
       return max_area;

    }
};