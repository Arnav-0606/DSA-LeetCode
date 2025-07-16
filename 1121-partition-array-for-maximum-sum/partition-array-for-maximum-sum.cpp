class Solution {
public:
    int partition(int i,int n,vector<int>& arr, int k,vector<int>&dp){
        if(i==n) return 0;
        if(dp[i]!=-1) return dp[i];
        int max_ = arr[i];
        int ans = INT_MIN;
        for(int j=0;j<k;j++){
            if(i+j == n) break;
            max_ = max(max_,arr[i+j]);
            int t = max_*(j+1) + partition(i+j+1,n,arr,k,dp);
            ans = max(ans,t);
        }
        return dp[i] =ans;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int>dp(n,-1);
        return partition(0,n,arr,k,dp);        
    }
};