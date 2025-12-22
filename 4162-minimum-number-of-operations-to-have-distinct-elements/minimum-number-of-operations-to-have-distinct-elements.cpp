class Solution {
public:
    int minOperations(vector<int>& nums) {
        int lastIndex = -1;
        unordered_set<int>s;
        int n = nums.size();
        for(int i=n-1;i>=0;i--){
            if(s.find(nums[i])!=s.end()){
                lastIndex = i;
                break;
            }
            s.insert(nums[i]);
        }
        if(lastIndex==-1) return 0;
        return ceil(double(lastIndex+1)/3.0);        
    }
};