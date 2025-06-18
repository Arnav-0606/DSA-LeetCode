class Solution {
public:
    int minCostClimbingStairs(vector<int>& nums) {
        int n = nums.size();
        int a = nums[n-1];
        int b = nums[n-2];
        for(int i=n-3;i>=0;i--){
            int c = nums[i]+min(a,b);
            a =b;
            b=c;
        }
        return min(a,b);

    }
};