class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int MinSoFar = nums[0];
        int maxDiff = -1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]>MinSoFar){
                maxDiff = max(maxDiff,nums[i]-MinSoFar);
            }
            MinSoFar = min(MinSoFar,nums[i]);
        }
        return maxDiff;
    }
};