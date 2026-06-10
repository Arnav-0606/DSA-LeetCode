class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int>next(n+1,0);
        for(int i=n;i>=1;i--){
            vector<int>curr(n+1,0);
            for(int j = 0;j<=n;j++){
                if(j==0 or (i>j and nums[i-1]>nums[j-1])){
                    curr[j] = max(curr[j],next[i]+1);                    
                }
                curr[j] = max(curr[j],next[j]);              
            }
            next = curr;
        }
        return next[0];
    }
};