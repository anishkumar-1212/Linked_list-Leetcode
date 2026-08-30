class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        
        // 1. Create a vector of pairs: {number, original_index}
        vector<pair<int, int>> indexed_nums(n);
        for (int i = 0; i < n; i++) {
            indexed_nums[i] = {nums[i], i};
        }
        
        // 2. Sort the array based on the numbers (pairs sort by first element by default)
        sort(indexed_nums.begin(), indexed_nums.end());
        
        // 3. Use two pointers on the sorted array
        int i = 0;
        int j = n - 1;
        
        while (i < j) {
            int current_sum = indexed_nums[i].first + indexed_nums[j].first;
            
            if (current_sum == target) {
                // Found the target! Return the original indices stored in the pairs
                return {indexed_nums[i].second, indexed_nums[j].second};
            } 
            else if (current_sum < target) {
                i++; // Sum is too small, move left pointer right to increase sum
            } 
            else {
                j--; // Sum is too big, move right pointer left to decrease sum
            }
        }
        
        return {};
    }
};
