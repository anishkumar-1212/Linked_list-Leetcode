class Solution {
public:
    int maxChunksToSorted(std::vector<int>& arr) {
        int max_seen = 0;
        int chunks = 0;
        
        for (int i = 0; i < arr.size(); ++i) {
            // Track the maximum value encountered so far
            max_seen = max(max_seen, arr[i]);
            
            // If the maximum value matches the current index, 
            // a valid independent chunk can be formed.
            if (max_seen == i) {
                chunks++;
            }
        }
        
        return chunks;
    }
};
