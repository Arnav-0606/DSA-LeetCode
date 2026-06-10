class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int>v;
        int n = nums.size();
        for(int i=0;i<n;i++){
            int idx = lower_bound(v.begin(),v.end(),nums[i])-v.begin();
            if(idx==v.size()){
                v.push_back(nums[i]);
            }
            else{
                v[idx] = nums[i];
            }
        }
        return v.size();
        
    }
};