class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int ans =0;
        int i=0,j=0;
        int zeroCnt =0;
        while(j<n){
            if(nums[j]==0) zeroCnt++;
            while(zeroCnt>1){
                if(nums[i]==0) zeroCnt--;
                i++;
            }
            ans = max(ans,j-i+1-zeroCnt);
            j++;
        }
        if(ans == n) return n-1;
        return ans;
        
    }
};