class Solution {
public:
    int fBottomUpSpaceOpt(const vector<int>&nums,int n){
    int a=0;
    int b=0;
    int c;
    for(int i=n-1;i>=0;i--){
        c = max(nums[i]+a,b);
        a=b;
        b=c;
  }
  return b;
}
int rob(vector<int>& nums){
  int n = nums.size();
  return fBottomUpSpaceOpt(nums,n);
}
};