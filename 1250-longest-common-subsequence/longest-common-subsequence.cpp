class Solution {
public:
    int f(const string &s1,const string &s2,int m,int n,vector<vector<int>>&dp){
  for(int i=m-1;i>=0;i--){
    for(int j=n-1;j>=0;j--){
      if(s1[i] == s2[j]){
      dp[i][j] = 1 + dp[i+1][j+1];
      }
      else{
        dp[i][j]=max(dp[i+1][j],dp[i][j+1]);
      }
}
}
  return dp[0][0];
}

    int longestCommonSubsequence(string s1, string s2) {
        int m = s1.size();
        int n = s2.size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,0));
        return f(s1,s2,m,n,dp);
    }
};