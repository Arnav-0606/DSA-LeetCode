class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int n = nums.size();
        int c = nums[0];
        int b = INT_MAX;
        int a = INT_MAX;
        for(int i=1;i<n;i++){
            if(nums[i]<b){
                if(nums[i]<a){
                    b = a;
                    a = nums[i];
                }
                else{
                    b = nums[i];
                }
            }
        }
        return a+b+c;        
    }
};