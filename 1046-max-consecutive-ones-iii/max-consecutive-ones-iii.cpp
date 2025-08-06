class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int zeroCnt =0;
        int i =0;
        int j =0;
        int ans = 0;
        while(j<n){
            if(nums[j]==0){
                zeroCnt++;
            }
            if(zeroCnt<=k){
                ans = max(ans,j-i+1);
            }
            while(zeroCnt>k){
                if(nums[i]==0) zeroCnt--;
                i++;
            }
            j++;
        }
        return ans;
        
    }
};