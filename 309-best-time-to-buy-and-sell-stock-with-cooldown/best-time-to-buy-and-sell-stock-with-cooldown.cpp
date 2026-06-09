class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>dp(n+3,vector<int>(n+1,0));
        for(int i=n;i>=1;i--){
            for(int j =0;j<=n;j++){
                if(j==0){
                    dp[i][j] = max(dp[i][j],dp[i+1][i]);
                }
                else{
                    // if(i>j)
                    dp[i][j] = max(dp[i+2][0]+(prices[i-1]-prices[j-1]),dp[i][j]);
                }
                dp[i][j] = max(dp[i][j],dp[i+1][j]);
            }
        }
        return dp[1][0];
    }
};
