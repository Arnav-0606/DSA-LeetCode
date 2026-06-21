class Solution {
public:
    bool check(long long sum,int x){
        long long c = sum;
        int f = sum%10;
        int last = f;
        while(c){
            last = c%10;
            c/=10;
        }
        return ((f==x) and (last==x));
    }
    int countValidSubarrays(vector<int>& nums, int x) {
        int n = nums.size();
        int ans =0;
        for(int i=0;i<n;i++){
            long long sum =0;
            for(int j =i;j<n;j++){
                sum += nums[j];
                if(check(sum,x)){
                    ans++;
                }
            }
        }
        return ans;
    }
};