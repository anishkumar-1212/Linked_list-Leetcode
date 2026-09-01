class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_so_far = prices[0];
        int result = 0;
        int n = prices.size();

        for (int i = 0; i < n; i++) {

            // Minimum price seen so far
            min_so_far = min(min_so_far, prices[i]);

            // Maximum profit by selling today
            result = max(result, prices[i] - min_so_far);
        }

        return result;
    }
};