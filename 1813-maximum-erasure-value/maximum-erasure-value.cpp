class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_set<int>s;
        int ans = INT_MIN;
        int sum =0;
        int  n = nums.size();
        int i =0,j=0;
        while(j<n){
            while(s.find(nums[j])!=s.end()){
                sum -= nums[i];
                s.erase(nums[i]);
                i++;
            }
            s.insert(nums[j]);
            sum+= nums[j];
            ans = max(sum,ans);
            j++;
        }
        return ans;
        
    }
};