class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int maxS =0;
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i =n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                if(matrix[i][j]==1){
                    dp[i][j]= 1+min({dp[i][j+1],dp[i+1][j],dp[i+1][j+1]});
                    maxS += dp[i][j];
                }
                else{
                    dp[i][j] =0;
                }
            }
        }
        return maxS;
        
    }
};