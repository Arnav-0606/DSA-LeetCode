class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int n = nums.size();
        int idx = 0;
        int curr_max = nums[0];
        int lmax = nums[0];
        for(int i =1;i<n-1;i++){
            curr_max = max(curr_max,nums[i]);
            if(nums[i]<lmax){
                lmax = curr_max;
                idx =i;
            }

        }
        return idx+1;
    }
};