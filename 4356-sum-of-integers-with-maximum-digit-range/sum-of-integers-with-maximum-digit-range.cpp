class Solution {
public:
    int digrange(int i){
        int mx = 0;
        int mn = 9;
        while(i){
            mx = max(mx,i%10);
            mn = min(mn,i%10);
            i/=10;
        }
        return mx-mn;
    }
    int maxDigitRange(vector<int>& nums) {
        map<int,vector<int>>mp;
        for(int i:nums){
            mp[(digrange(i))].push_back(i);
        }
        int mx = 0;
        for(auto [k,v]:mp){
            mx = max(mx,k);
        }
        return accumulate(mp[mx].begin(),mp[mx].end(),0);
    }
};