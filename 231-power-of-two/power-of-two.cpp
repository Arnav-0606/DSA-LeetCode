class Solution {
public:
    bool f(int n){
        if(n<=0) return false;
        if(n==1) return true;
        if(n&1) return false;
        return f(n/2);
    }
    bool isPowerOfTwo(int n) {
        return f(n);
    }
};