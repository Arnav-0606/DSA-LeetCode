class Solution {
public:
    int ans =0;
    void merge(vector<int>& arr, int s, int m, int e) {
        vector<int> temp(e - s + 1);
        int i = s, j = m + 1, k = 0;

        while (i <= m && j <= e) {
            if (arr[i] <= arr[j]) temp[k++] = arr[i++];
            else temp[k++] = arr[j++];
        }
        while (i <= m) temp[k++] = arr[i++];
        while (j <= e) temp[k++] = arr[j++];

        for (int t = 0; t < temp.size(); t++) arr[s + t] = temp[t];
    }
    void mergeSort(vector<int>&nums,int s,int e){
        if(s==e) return;
        int m = s + (e-s)/2;
        mergeSort(nums,s,m);
        mergeSort(nums,m+1,e);
        int j = m+1;
        for(int i =s;i<=m;i++){
            while(j<=e and 1LL*nums[i]>2LL*nums[j]) j++;
            ans += (j-m-1);           
        }
        merge(nums,s,m,e);
    }

    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        mergeSort(nums,0,n-1);        
        return ans;
    }
};