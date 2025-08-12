class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k<=1) return 0;
        int i =0,j=0;
        int ans =0;
        int n = nums.size();
        long long currProd =1;
        while(j<n){
            currProd *= nums[j];
            while(currProd >= k and i<=j){
                currProd /= nums[i];
                i++;
            }
            ans += (j-i+1);
            j++;
        }
        return ans;
    }
};