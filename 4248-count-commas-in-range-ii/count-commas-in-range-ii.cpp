class Solution {
public:
    long long countCommas(long long n) {
        long long t = 1e3;
        long long ans = 0;
        while(n>=t){
            ans += (n-t+1);
            t*= 1e3;
        }
        return ans;
    }
};