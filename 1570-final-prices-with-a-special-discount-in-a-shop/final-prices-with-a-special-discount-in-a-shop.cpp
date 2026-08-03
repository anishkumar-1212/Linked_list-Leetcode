class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        stack<int> st; // stores indices

        for (int i = 0; i < prices.size(); i++) {

            while (!st.empty() && prices[i] <= prices[st.top()]) {
                prices[st.top()] -= prices[i];
                st.pop();
            }

            st.push(i);
        }

        return prices;
    }
};