class Solution {
public:
    bool isDigitorialPermutation(int n) {
        long long fac[10] = {1};
        for(int i=1;i<10;i++){
            fac[i] = fac[i-1]*i;                        
        }
        long long sum = 0;
        int c = n;
        int mp1[10] = {0},mp2[10] = {0};
        while(c){
            mp1[c%10]++;
            sum += fac[c%10];
            c/=10;
        }
        while(sum){
            mp2[sum%10]++;
            sum/=10;
        }
        for(int i=0;i<10;i++){
            if(mp1[i]!=mp2[i]) return false;
        }
        return true;
    }
};