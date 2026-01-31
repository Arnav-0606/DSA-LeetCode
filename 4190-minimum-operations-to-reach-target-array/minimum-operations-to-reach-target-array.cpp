class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& target) {
        set<int>s;
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]!=target[i]){
                s.insert(nums[i]);
            }
        }
        return s.size();
        
    }
};