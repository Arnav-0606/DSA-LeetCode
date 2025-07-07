class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
    int maxArea = 0;
    int n = matrix.size();						
    int m = matrix[0].size();
    vector<vector<int>>dp(n+1,vector<int>(m+1,0));
    for(int i =n-1;i>=0;i--){
    	for(int j=m-1;j>=0;j--){
        if(matrix[i][j]=='1'){
            dp[i][j] = min({dp[i][j+1],dp[i+1][j],dp[i+1][j+1]})+1;
            maxArea = max(dp[i][j],maxArea);
        }
        else continue;
    }
    }
    return maxArea*maxArea;  
    }
};