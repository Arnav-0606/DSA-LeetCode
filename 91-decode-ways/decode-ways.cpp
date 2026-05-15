class Solution {
public:
    int numDecodings(string s) {

        int n = s.size();

        if(s[0]=='0') return 0;

        for(int i=1;i<n;i++){
            if(s[i]=='0' && (s[i-1]!='1' && s[i-1]!='2')){
                return 0;
            }
        }

        vector<int> dp(n+1,0);

        dp[n] = 1;

        if(s[n-1]!='0') dp[n-1] = 1;

        for(int i=n-2;i>=0;i--){

            if(s[i]=='0'){
                dp[i]=0;
                continue;
            }

            dp[i] += dp[i+1];

            int t = (s[i]-'0')*10 + (s[i+1]-'0');

            if(t>=10 && t<=26){
                dp[i] += dp[i+2];
            }
        }

        return dp[0];
    }
};