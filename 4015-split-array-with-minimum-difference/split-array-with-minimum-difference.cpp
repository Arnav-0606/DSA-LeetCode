class Solution {
public:
    long long splitArray(vector<int>& nums) {
        long long ans = LLONG_MAX;
        int n = nums.size();
        long long sum = accumulate(nums.begin(),nums.end(),0LL);
        vector<bool>pref(n);
        vector<bool>suff(n);
        pref[0] = true;
        suff[n-1] = true;
        for(int i=1;i<n;i++){
            pref[i] = pref[i-1] and (nums[i]>nums[i-1]);
            suff[n-i-1] = suff[n-i] and (nums[n-i-1]>nums[n-i]);
        }
        long long currSum =0;
        for(int i=0;i<n-1;i++){
            currSum += nums[i];
            if(pref[i] and suff[i+1]){
                ans = min(abs(sum-2*currSum),ans);           
            }
        }
        return (ans==LLONG_MAX) ? -1: ans;
    }
};