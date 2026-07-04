class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        vector<int>kClosestElements;
        int lb = lower_bound(arr.begin(),arr.end(),x)-arr.begin();
        int ub = upper_bound(arr.begin(),arr.end(),x)-arr.begin();
        if(lb==ub)lb--;
        int t = ub-lb-1;
        while(k>0 and t>0){
            kClosestElements.push_back(x);
            t--;
            k--;
        }

        while(lb>=0 and ub<n and k>0){
            if(abs(arr[ub]-x)<abs(arr[lb]-x)){
                kClosestElements.push_back(arr[ub]);
                ub++;
            }
            else{
                kClosestElements.push_back(arr[lb]);
                lb--;
            }
            k--;
        }
        if(k>0 and lb<0){
            while(k--){
                kClosestElements.push_back(arr[ub]);
                ub++;
            }
        }
        else if(k>0 and ub>=n){
            while(k--){
                kClosestElements.push_back(arr[lb]);
                lb--;
            }
        }
        sort(kClosestElements.begin(),kClosestElements.end());
        return kClosestElements;
    }
};