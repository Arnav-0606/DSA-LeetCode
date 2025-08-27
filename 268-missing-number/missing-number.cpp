class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        
        long long exp = (n * (n+1))/2;
        long long act = accumulate(nums.begin(),nums.end(),0);
        return exp-act;
    }
};