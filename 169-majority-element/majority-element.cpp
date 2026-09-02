class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        int j=0;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++) {
            if(nums[i]==nums[j]){
                count++;
            }else{
                j++;
            }
            if(count>n/2){
                return nums[i];
            }
        }
        return -1;
    }
};