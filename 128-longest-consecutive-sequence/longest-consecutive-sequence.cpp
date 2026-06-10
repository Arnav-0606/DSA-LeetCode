class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int ans = 0;
        unordered_set<int>s;
        int n = nums.size();
        for(int i=0;i<n;i++){
            s.insert(nums[i]);
        }
        for(int i=0;i<n;i++){
            if(s.count(nums[i]) and !s.count(nums[i]-1)){
            int t = nums[i];
            int cnt = 0;
            while(s.count(t)){
                s.erase(t);
                cnt++;
                t++;
            }
            ans = max(ans,cnt);
            }
        }
        return ans;
    }
};