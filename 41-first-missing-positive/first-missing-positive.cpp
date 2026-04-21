class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        for(int j=1;j<=n;j++){
            if(mp.find(j)==mp.end()) return j;
        }
        return n+1;
        
    }
};