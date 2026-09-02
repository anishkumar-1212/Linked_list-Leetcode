class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (nums[i] == nums[j]) {
                    count++;
                } else {
                    count = 0;
                }
                if (count > n / 2) {
                    return nums[i];
                }
            }
        }
        return -1;
    }
};