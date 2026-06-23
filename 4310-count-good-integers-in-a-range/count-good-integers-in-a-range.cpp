class Solution {
public:
    long long dp[16][10][2][2];
    long long f(int i,int last, bool tight,bool lz,string digits,int k){
        if(i==digits.size()) return 1;
        if(dp[i][last][tight][lz]!=-1) return dp[i][last][tight][lz];
        int lb =0;
        int ub = (tight)?digits[i]-'0':9;
        long long sum =0;
        for(int d=lb;d<=ub;d++){
            if(!lz && abs(d-last)>k) continue;
            sum += f(i+1,d,tight &&(d==ub),lz and (d==0),digits,k);
        }
        return dp[i][last][tight][lz] = sum;
    }
    long long goodIntegers(long long l, long long r, int k) {
        memset(dp,-1,sizeof(dp));
        string sl = to_string(l-1);
        string sr = to_string(r);
        long long fl = f(0,0,true,true,sl,k);
        memset(dp,-1,sizeof(dp));
        long long fr = f(0,0,true,true,sr,k);
        return (fr-fl);
        
    }
};