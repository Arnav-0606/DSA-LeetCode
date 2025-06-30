class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        int ans =0;
        for(auto it : mp){
            if(mp.find(it.first+1)!=mp.end()){
                ans = max(it.second+mp[it.first+1],ans);
            }
        }
        return ans;
    }
};