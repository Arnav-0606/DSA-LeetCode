class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<long long>dp(m+1,0);
        if(grid[n-1][m-1]==0) dp[m-1] = 1;
        for(int i =n-1;i>=0;i--){
            for(int j = m-1;j>=0;j--){
                if(grid[i][j]==1)  dp[j] = 0;
                else dp[j] = dp[j] + dp[j+1];
            }
        }
        return dp[0];
    }
};