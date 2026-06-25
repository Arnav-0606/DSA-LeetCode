class Solution {
public:
    bool f(int m,auto&nums,int k){
        int cnt =0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>=m)cnt++;
        }
        return cnt>=k;
    }
    int findKthLargest(vector<int>& nums, int k) {
        int lb = *min_element(nums.begin(),nums.end());
        int ub = *max_element(nums.begin(),nums.end());
        int ans = 0;
        while(lb<=ub){
            int mid = (ub-lb)/2 + lb;
            if(f(mid,nums,k)){
                ans = mid;
                lb = mid +1;
            }
            else{
                ub = mid-1;
            }

        }
        return ans;
    }
};