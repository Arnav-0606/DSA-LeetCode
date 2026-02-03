class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();
        int i =1;
        while(i<n-1 and nums[i]>nums[i-1]){
            i++;
        }
        if(i == n-1){
            return false;
        }
        int j = i--;
        if(i==0) return false;
        while(j<n and nums[j]<nums[j-1]){
            j++;
        }
        if(j==n) return false;
        int k = j--;
        while(k<n and nums[k]>nums[k-1]){
            k++;
        }
        if(k==n) return true;
        return false;   
    }
};