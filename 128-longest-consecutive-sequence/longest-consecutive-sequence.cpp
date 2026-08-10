class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int ans=0;
        unordered_set<int> s(nums.begin(),nums.end());
        for(auto v:s){
            int count=1;
            int curr=v;
            if(s.count(curr-1)){
                continue;
            }else{
                while(s.count(curr+1)){
                    curr++;
                    count++;

                }
                ans=max(ans,count);
            }
        }
        return ans;
    }
};