class Solution {
public:
    int findLucky(vector<int>& arr) {
        int ans=-1;
        unordered_map<int,int>mp;
        for(int num:arr){
            mp[num]++;
        }
        for(auto [k,v]:mp){
            if(k==v) ans= max(ans,k);
        }
        return ans;
    }
};