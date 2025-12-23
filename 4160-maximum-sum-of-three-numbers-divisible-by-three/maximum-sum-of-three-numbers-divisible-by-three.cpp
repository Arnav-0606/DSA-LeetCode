class Solution {
public:
    int maximumSum(vector<int>& nums) {
        vector<int>v0;
        vector<int>v1;
        vector<int>v2;
        int n = nums.size();
        for(int i=0;i<n;i++){
            int p = nums[i];
            if(p%3==0){
                v0.push_back(p);
            }
            else if(p%3==1){
                v1.push_back(p);
            }
            else{
                v2.push_back(p);
            }
        }
        sort(v1.begin(),v1.end());
        sort(v2.begin(),v2.end());
        sort(v0.begin(),v0.end());
        int ans = 0;
        int a = v0.size();
        int b = v1.size();
        int c = v2.size();

        if((a>=1) and (b>=1) and (c>=1)){
            ans = max(ans,v0[a-1]+v1[b-1]+v2[c-1]);
        }
        if(a>=3){
            ans = max(v0[a-1]+v0[a-2]+v0[a-3],ans);
        }
        if(b>=3){
            ans = max(v1[b-1]+v1[b-2]+v1[b-3],ans);
        }
        if(c>=3){
            ans = max(v2[c-1]+v2[c-2]+v2[c-3],ans);
        }
        return ans;        
    }
};