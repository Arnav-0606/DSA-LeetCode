class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int n = nums.size();
        int ans =0;
        vector<int>lmax(n,-1);
        vector<int>rmin(n,1e9);
        for(int i =1;i<n;i++){
            lmax[i] = max(lmax[i-1],nums[i-1]);
        }
        for(int i =n-2;i>=0;i--){
            rmin[i] = min(rmin[i+1],nums[i+1]);
        }

        if(rmin[0]>=nums[0]) return 1;
        int i =1;
        for(i=1;i<n-1 and lmax[i]>rmin[i];i++){
        }
        return i+1;
    }
};