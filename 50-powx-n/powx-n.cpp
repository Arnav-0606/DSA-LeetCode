class Solution {
public:
    double calcPow(double x,long long n){
        if(n==0) return 1;
        double t = myPow(x,n/2);
        if(n&1){
            return t*t*x;
        }
        return t*t;
    }
    double myPow(double x, int n) {
        long long ne = n;
        if(n<0){
            x = (1/x);
            ne = - ne;
        }
        return calcPow(x,ne);
    }
};