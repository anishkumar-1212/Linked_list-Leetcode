class Solution {
public:
    int maxArea(vector<int>& height) {
        int max_water = 0;
        int left = 0;
        int right = height.size() - 1;

        while (left < right) {
            // 1. Calculate width and height
            int width = right - left;
            int current_height = min(height[left], height[right]);
            
            // 2. Track the maximum product
            int current_water = width * current_height;
            max_water = max(max_water, current_water);

            // 3. Move the pointer with the shorter bar
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }

        return max_water;
    }
};
