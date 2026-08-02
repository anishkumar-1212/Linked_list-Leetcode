class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans(nums1.size());
        stack<int> st;
        unordered_map<int, int> m;

        // Traverse nums2 from right to left
        for (int i = nums2.size() - 1; i >= 0; i--) {

            // Remove all smaller or equal elements
            while (!st.empty() && st.top() <= nums2[i]) {
                st.pop();
            }

            if (st.empty()) {
                m[nums2[i]] = -1;
            } else {
                m[nums2[i]] = st.top();
            }

            st.push(nums2[i]);
        }

        // Get answers for nums1
        for (int i = 0; i < nums1.size(); i++) {
            ans[i] = m[nums1[i]];
        }

        return ans;
    }
};