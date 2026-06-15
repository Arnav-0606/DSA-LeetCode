class Solution {
public:
    bool f(string s,int i,auto & dict,string currStr,vector<int>&dp){
        if(i==s.size()) {
            if(currStr == "") return true;
            return false;
        }
        currStr += s[i];
        if(dict.count(currStr)){
            if(dp[i+1]==-1){
            dp[i+1] = f(s,i+1,dict,"",dp);
            }
            return (dp[i+1] or f(s,i+1,dict,currStr,dp));
        }
        else{
            return f(s,i+1,dict,currStr,dp);
        }
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string>dict;
        int n = s.size();
        vector<int>dp(n+1,-1);
        for(auto t : wordDict) dict.insert(t);
        return f(s,0,dict,"",dp);
    }
};