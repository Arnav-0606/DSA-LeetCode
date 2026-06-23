class Solution {
public:
    int dp[10][2][10];
    int f(int i,bool tight,int cnt,auto&digits){
        if(i==digits.size()) {
            return cnt;
        }
        if(dp[i][tight][cnt]!=-1) return dp[i][tight][cnt];

        int ub = (tight)? digits[i] : 9;
        int sum = 0;
        for(int k=0;k<=ub;k++){
            sum += (f(i+1,tight && (k==ub), cnt + (k==1),digits));
        }
        return dp[i][tight][cnt] = sum;
        
    }
    int countDigitOne(int n) {
        if(n==0) return 0;
        vector<int>digits;
        int c = n;
        while(c){
            digits.push_back(c%10);
            c/=10;
        }
        reverse(digits.begin(),digits.end());
        memset(dp,-1,sizeof(dp));
        return f(0,true,0,digits);

    }
};