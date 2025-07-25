class Solution {
public:
    int maxSum(vector<int>& nums) {
        set<int>s;
        int ans=0;
        int m = nums[0];
        bool flag = false;
        for(int num:nums){
            if(num>0){
            flag = true;
            if(s.find(num)==s.end()){
                ans+= num;
                s.insert(num);
            }
            }
            else{
                m = max(m,num);
            }
        }
        if(flag) return ans;
        return m;        
    }
};