class Solution {
public:
    int f(int i,vector<int>&prices,int StockHold,vector<vector<int>>&dp){
        if(i==prices.size()){
            return 0;
        }
        if(dp[i][StockHold]!=-1){
            return dp[i][StockHold];
        }
        int ans = INT_MIN;
        if(StockHold){
            ans = prices[i]+ f(i+1,prices,0,dp);        
        }
        else{
            ans = -prices[i]+f(i+1,prices,1,dp);
        }
        return dp[i][StockHold] = max(ans,f(i+1,prices,StockHold,dp));
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return f(0,prices,0,dp);
    }
};