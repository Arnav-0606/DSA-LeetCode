class Solution {
public:
    bool checkPrime(int n){
        if(n <= 1) return false;
        for(int i =2; i*i <=n;i++){
            if(n%i==0) return false;
        }
        return true;
    }
    long long splitArray(vector<int>& nums) {
        long long A = 0;
        long long B = 0;
        for(int i =0;i<nums.size();i++){
            if(checkPrime(i)){
                A+=nums[i];
            }
            else{
                B+=nums[i];
            }
        }
        return abs(A-B);
    }
};