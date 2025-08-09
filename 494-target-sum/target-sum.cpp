class Solution {
public:
    int f(vector<int>&nums,int t,int i,vector<unordered_map<int,int>>&dp){
        //base case
        if(i==nums.size()){
            if(t==0){
            return 1;
            }
            return 0;
        }
        if(dp[i].find(t)!=dp[i].end()) return dp[i][t];
        //recursive case
        return dp[i][t] = f(nums,t-nums[i],i+1,dp)+f(nums,t+nums[i],i+1,dp);
    }
    int findTargetSumWays(vector<int>& nums, int t) {
        int n = nums.size();
        vector<unordered_map<int,int>>dp(n);
        return f(nums,t,0,dp);
    }
};