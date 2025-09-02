class Solution {
public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations) {
        unordered_map<int,int>mp;
        int n = nums.size();
        for(int i=0;i<n;i++){
            mp[nums[i]]=i;
        }
        for(int i =0;i<operations.size();i++){
            int a = operations[i][0];
            int b = operations[i][1];
            int idx = mp[a];
            mp.erase(a);
            mp[b] = idx;
        }
        vector<int>ans(n);
        for(auto [k,v]:mp){
            ans[v] =k;
        }
        return ans;
       
        
    }
};