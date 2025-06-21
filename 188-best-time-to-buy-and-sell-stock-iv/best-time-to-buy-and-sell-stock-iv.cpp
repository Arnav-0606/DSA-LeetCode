class Solution {
public:
    int f(const vector<int>&prices,int N,int K){
        vector<vector<int>> dp(N + 1, vector<int>(K + 1, 0));
        for (int i = N - 1; i >= 0; i--) {
            for (int k = 1; k <= K; k++) {
                int donotBuyOption = dp[i + 1][k];
                int buyOptionMaxSofar = 0;
                for (int j = i + 1; j <= N - 1; j++) {
                    buyOptionMaxSofar = max(buyOptionMaxSofar, (prices[j] - prices[i]) + dp[j + 1][k - 1]);
                }
                dp[i][k] = max(donotBuyOption, buyOptionMaxSofar);
            }
        }
        return dp[0][K];
    }

    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        return f(prices,n,k);
    }
};