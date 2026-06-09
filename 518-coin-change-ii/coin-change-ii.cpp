class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        int mod = 1e9 + 7;
        vector<unsigned int>dp(amount+1,0);
        dp[0] = 1;
        for(int i=n-1;i>=0;i--){
            for(int j = 0;j<=amount;j++){
                // dp[i][j] = dp[i+1][j];
                if(j-coins[i]>=0){
                    dp[j] += (dp[j-coins[i]]);
                }
            }
        }
        return (int)dp[amount];
    }
};