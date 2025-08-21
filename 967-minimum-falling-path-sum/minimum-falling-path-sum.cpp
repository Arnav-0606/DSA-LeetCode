class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>>dp(n+1,vector<int>(m,0));
        for(int i =n-1;i>=0;i--){
            for(int j =m-1;j>=0;j--){
                if (j == 0 && j == m-1) { 
                    dp[i][j] = matrix[i][j] + dp[i+1][j];
                }
                else if(j==0){
                    dp[i][j] = matrix[i][j]+min(dp[i+1][j],dp[i+1][j+1]);
                }
                else if(j==m-1){
                    dp[i][j] = matrix[i][j] + min(dp[i+1][j],dp[i+1][j-1]);
                }
                else{
                     dp[i][j] = matrix[i][j]+min({dp[i+1][j],dp[i+1][j-1],dp[i+1][j+1]});
                }
            }
        }
        return *min_element(dp[0].begin(),dp[0].end());
    }
};