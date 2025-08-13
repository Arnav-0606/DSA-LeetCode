class Solution {
public:
    int MOD = 1e9 +7;
    long long pow(int  a,long long x){
        if(x==0) return 1;
        long long t = pow(a,x/2)%MOD;
        if(x&1){
            return (a*((t*t)%MOD))%MOD;
        }
        return t*t%MOD;
    }
    int countGoodNumbers(long long n) {
        long long t = n/2;
        long long t1 = pow(4,t)%MOD;
        long long t2 = pow(5,t)%MOD;
        long long mul = (t1*t2)%MOD;
        if(n&1) return (5*mul)%MOD;
        return mul;
    }
};