class Solution {
public:
    bool partitionArray(vector<int>& nums, int k) {
        int maxR = 0;
        unordered_map<int,int>mp;
        int n = nums.size();
        if(n%k != 0) return false;
        int grps = n/k;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        for(auto [k,v] : mp){
            maxR =max(maxR,v);
        }
        return maxR <= grps;
    }
};