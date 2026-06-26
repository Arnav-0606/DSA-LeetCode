class Solution {
public:
    long long maxTotal(vector<int>& nums, string s) {
        int lastNotTaken = -1;
        long long ans = 0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='1'){
                if(lastNotTaken >= nums[i]){
                    ans += lastNotTaken;
                    lastNotTaken = nums[i];
                }
                else{
                    ans += nums[i];
                }
            }
            else{
                lastNotTaken = nums[i];
            }
        }
        return ans;
    }
};