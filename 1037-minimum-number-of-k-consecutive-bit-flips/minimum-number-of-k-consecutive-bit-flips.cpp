class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size();
        vector<bool>flip(n,false);
        bool fl = false;
        int ans = 0;
        for(int i=n-1;i>=0;i--){
            if((!fl and (nums[i]==0)) or (fl and nums[i]==1)){
                ans++;
                if(i-k+1<0) return -1;
                flip[i-k+1] = true;
                fl = 1- fl;
            } 
            if(flip[i]){
                fl = 1-fl;
            }

        }
        return ans;
    }
};