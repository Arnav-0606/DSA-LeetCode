class Solution {
public:
    bool f(vector<int>&nums,int i,int t,vector<vector<int>>&dp){
        //base case
        if(t==0) return true;
        if(i==nums.size() or t<0) return false;
        //recursive
        if(dp[i][t]!=-1){
            return dp[i][t];
        }
        return dp[i][t]=(f(nums,i+1,t-nums[i],dp) or f(nums,i+1,t,dp));
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum =0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        if(sum&1) return false;
        int t = sum/2;
        vector<vector<int>>dp(n+1,vector<int>(t+1,-1));
        return f(nums,0,t,dp);
    }
};