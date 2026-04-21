class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        if(nums[0]>1) return 1;
        for(int i=0;i<n;i++){
            if(nums[i]<=1) continue;
            if(nums[i]-nums[i-1]>1){
                return max(1,nums[i-1]+1);
            }       
        }
        return max(1,nums[n-1]+1);
        
    }
};