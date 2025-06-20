class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int>dp(amount+1,INT_MAX);
        dp[amount]=0;
        for(int i=amount;i>0;i--){
            if(dp[i]==INT_MAX) continue;
            for(int j=0;j<coins.size();j++){
                if(i-coins[j]>=0){
                    dp[i-coins[j]]= min(dp[i-coins[j]],dp[i]+1);
                }
            }
        }
        return (dp[0]==INT_MAX)?-1:dp[0];
    }
};