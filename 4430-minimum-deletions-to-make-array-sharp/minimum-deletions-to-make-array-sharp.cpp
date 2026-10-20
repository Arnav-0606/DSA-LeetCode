class Solution {
public:
    int minDeletions(vector<int>& nums) {
        int last = 0;
        int ans =0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==last){
                ans++;
            }
            else last = nums[i];
        }
        return ans;
        
    }
};