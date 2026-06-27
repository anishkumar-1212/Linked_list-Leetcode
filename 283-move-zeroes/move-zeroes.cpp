class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int k = 0;

        // Step 1: move all non-zero elements
        for (int i = 0; i < n; i++) {
            if (nums[i] != 0) {
                nums[k++] = nums[i];
            }
        }

        // Step 2: fill remaining with 0
        while (k < n) {
            nums[k++] = 0;
        }
    }
};