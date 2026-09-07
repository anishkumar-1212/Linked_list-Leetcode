class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currentsum = 0, maxsum = INT_MIN;
        for(int val : nums){
            currentsum += val;
            maxsum = max(currentsum, maxsum);
            if(currentsum < 0){
                currentsum = 0;  // reset inside the loop
            }
        }
        return maxsum;
    }
};
