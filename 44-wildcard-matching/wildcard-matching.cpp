class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        vector<vector<bool>>dp(n+1,vector<bool>(m+1,false));
        dp[n][m] = true;
        for(int j = m-1; j >= 0; j--){
            if(p[j] == '*')
                dp[n][j] = dp[n][j+1];
            else
                dp[n][j] = false;
        }
        for(int i=n-1;i>=0;i--){
            for(int j =m-1;j>=0;j--){
                if(s[i]==p[j] or p[j]=='?'){
                    dp[i][j] = dp[i+1][j+1];
                }
                else if(p[j]=='*'){
                    dp[i][j] = (dp[i+1][j+1] or dp[i+1][j] or dp[i][j+1]);
                }
            }
        }
        return dp[0][0];
    }
}; 