class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int ans = INT_MAX;
        int n = nums.size();
        for(int i=0;i<k;i++){
            for(int j=0;j<k;j++){
                if(i==j)continue;
                int cnt = 0;
                for(int a =0;a<n;a++){
                    if(a&1){
                        int t= abs(nums[a]%k - i);
                        cnt +=min(t,k-t);
                    }
                    else{
                        int t = abs(nums[a]%k - j);
                        cnt +=min(t,k-t);
                    }
                }
                ans = min(ans,cnt);
            }
        }
        return ans;
        
    }
};