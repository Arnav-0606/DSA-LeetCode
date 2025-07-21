class Solution {
public:
    int cnt;
    void f(int i,vector<int>&arr,int n){
        if(i==n+1){
            cnt++;
            return;
        }
        for(int j = i;j<n+1;j++){
            swap(arr[i],arr[j]);
            if(arr[i]%i==0 or i % arr[i]==0){
                f(i+1,arr,n);
            }
            swap(arr[i],arr[j]);
        }
    }
    int countArrangement(int n) {
        vector<int>arr(n+1,0);
        for(int i =1;i<n+1;i++){
            arr[i] = i;
        }
        f(1,arr,n);
        return cnt;
    }
};