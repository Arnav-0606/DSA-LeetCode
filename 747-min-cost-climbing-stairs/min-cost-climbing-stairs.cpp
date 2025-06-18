class Solution {
public:
    int minCostClimbingStairs(vector<int>& nums) {
        int n = nums.size();
        int a = nums[0];
        int b = nums[1];
        for(int i=2;i<n;i++){
            int c = nums[i]+min(a,b);
            a=b;
            b=c;
        }
        return min(a,b);

    }
};