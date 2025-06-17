class Solution {
public:
    void f(int s,vector<int>&nums,vector<int>&curr,vector<vector<int>>&ans){
        for(int i=s;i<nums.size();i++){
            if(i != s and nums[i]==nums[i-1]) continue;
            curr.push_back(nums[i]);
            f(i+1,nums,curr,ans);
            curr.pop_back();
        }
        ans.push_back(curr);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int>curr;
        vector<vector<int>>ans;
        f(0,nums,curr,ans);
        return ans;
    }
};