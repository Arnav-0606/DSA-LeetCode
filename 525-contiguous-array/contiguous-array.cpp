class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int>mp;
        int t =0;
        int ans =0;
        mp[0]=-1;
        for(int i=0;i<n;i++){
            int num = nums[i];
            if(num==0) t--;
            else t++;
            if(mp.find(t)!=mp.end()){
                ans = max(ans,i-mp[t]);
            }
            else{
                mp[t] = i;
            }
        }
        return ans;
        
    }
};