class Solution {
public:
    int minCostClimbingStairs(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n);
        dp[n-1] = nums[n-1];
        dp[n-2] = nums[n-2];
        for(int i=n-3;i>=0;i--){
            dp[i]=nums[i]+min(dp[i+1],dp[i+2]);
        }
        return min(dp[0],dp[1]);

    }
};