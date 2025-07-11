class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int n = dungeon.size();
        int m = dungeon[0].size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,INT_MAX));
        for(int i=n-1;i>=0;i--){
            for(int j =m-1;j>=0;j--){
                if(i==n-1 and j ==m-1){
                    dp[i][j] = dungeon[i][j]>0 ? 1 : abs(dungeon[i][j])+1;
                }
                else{
                    int right = dp[i][j+1];
                    int down = dp[i+1][j];
                    int ans = min(right,down) - dungeon[i][j];
                    dp[i][j] = ans>0 ? ans:1;
                }
            }
        }
        return dp[0][0];
    }
};