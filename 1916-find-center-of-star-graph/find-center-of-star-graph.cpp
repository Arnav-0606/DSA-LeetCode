class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_map<int,int>mp;
        for(auto t :edges){
            int k = t[0];
            int v = t[1];
            mp[k]++;
            mp[v]++;
        }
        int ans =0;
        int m =0;
        for(auto [k,v]:mp){
            if(v>m){
                ans = k;
                m = v;
           }
        }
        return ans;

        
    }
};