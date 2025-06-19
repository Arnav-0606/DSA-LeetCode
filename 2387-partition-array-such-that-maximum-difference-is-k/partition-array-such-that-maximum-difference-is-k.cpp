class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int s = nums[0];
        int cnt =1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]-s>k){
                s = nums[i];
                cnt++;
            }
        }
        return cnt;
    }
};