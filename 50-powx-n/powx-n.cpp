class Solution {
public:
    double calcPow(double x,int n){
        if(n==0) return 1;
        double t = myPow(x,n/2);
        if(n&1){
            return t*t*x;
        }
        return t*t;
    }
    double myPow(double x, int n) {
        if(n<0){
            x = (1/x);
            if (n == INT_MIN) {
                return x * calcPow(x, INT_MAX);
            }
            n = abs(n);
        }
        return calcPow(x,n);
    }
};