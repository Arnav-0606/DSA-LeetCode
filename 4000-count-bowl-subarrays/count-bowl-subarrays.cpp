class Solution {
public:
    long long bowlSubarrays(vector<int>& nums) {
        stack<int>s;
        int n = nums.size();
        vector<int> NGR(n,-1),NGL(n,-1);
        for(int i=0;i<n;i++){
            while(!s.empty() and nums[s.top()]<nums[i])s.pop();
            if(!s.empty()) NGL[i] = s.top();
            s.push(i);
        }
        while(!s.empty()) s.pop();
        for(int i=n-1;i>=0;i--){
            while(!s.empty() and nums[s.top()]<nums[i])s.pop();
            if(!s.empty()) NGR[i] = s.top();
            s.push(i);
        }
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            if(NGL[i]!=-1 and i-NGL[i]>=2)ans++;
            if(NGR[i]!=-1 and NGR[i]-i>=2) ans++;
        }
        return ans;
    }
};