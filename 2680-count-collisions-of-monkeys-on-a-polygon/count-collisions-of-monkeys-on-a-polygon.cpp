class Solution {
public:
    const int MOD = 1e9+7;
    long long calc(long long n){
        if(n==0) return 1;
        long long t = calc(n/2)%MOD; 
        if(n&1) return (t * t * 2)%MOD;
        return (t*t)%MOD;
    }
    int monkeyMove(int n) {
        return (calc(n) -2+MOD)%MOD;
    }
};