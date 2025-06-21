class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n,0);
        dp[0] =1;
        for(int i=0;i<n-1;i++){
            if(dp[i]==0) continue;
            for(int j=1;j<=nums[i] and i+j<n;j++){
                dp[i+j] =1;
            }
        }
        return dp[n-1];
    }
};