class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        unordered_map<int,int>mp;
        int n = nums.size();
        int t = (1<<n);
        int op =0;
        for(int i =0;i<t;i++){
            int ans = 0;
            for(int j =0;j<n;j++){
                if((i>>j)&1){
                    ans = ans | nums[j];
                }
            }
            mp[ans]++;
        }
        int mx = INT_MIN;
        for(auto k : mp){
            mx = max(mx,k.first);
        }
        return mp[mx];
    }
};