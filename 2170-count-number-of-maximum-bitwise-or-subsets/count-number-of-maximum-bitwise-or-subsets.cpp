class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int n = nums.size();
        int t = (1<<n);
        int maxOr = 0;
        int op =0;
        for(int i =0;i<t;i++){
            int ans = 0;
            for(int j =0;j<n;j++){
                if((i>>j)&1){
                    ans = ans | nums[j];
                }
            }
            if(ans==maxOr){
                op++;                                                
            }
            else if(ans>maxOr){
                op =1;
                maxOr = ans;
            }
        }
        return op;
    }
};