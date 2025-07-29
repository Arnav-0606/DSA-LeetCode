class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int n = nums.size();
        int ans =0;
        vector<int>lmax(n,nums[0]);
        vector<int>rmin(n,nums[n-1]);
        for(int i =1;i<n;i++){
            lmax[i] = max(lmax[i-1],nums[i]);
        }
        for(int i =n-2;i>=0;i--){
            rmin[i] = min(rmin[i+1],nums[i]);
        }
        for(int i =0;i<n-1;i++){
            if(lmax[i]<=rmin[i+1]) return i+1;
        }
        return 1;
    }
};