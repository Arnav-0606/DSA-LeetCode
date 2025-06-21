class Solution {
public:
    int rob(vector<int>& nums) {
        int a=0;
        int b=0;
        int c;
        int n = nums.size();
        if(n==1) return nums[0];
        for(int i=n-1;i>=1;i--){
        c = max(nums[i]+a,b);
        a=b;
        b=c;
  }
    int ans1 = b;
    a=0,b=0;
    for(int i=n-2;i>=0;i--){
        c = max(nums[i]+a,b);
        a=b;
        b=c;
  }
  return max(b,ans1);  
    }
};