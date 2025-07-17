class Solution {
public:
    bool isPossible(int mid,int k,const vector<vector<int>>& matrix,int n,int m){
        int cnt=0;
        for(int i=0;i<n;i++){
            cnt += upper_bound(matrix[i].begin(),matrix[i].end(),mid)-matrix[i].begin();
        }
        return cnt>=k;
    }
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int m = matrix[0].size();
        int s = matrix[0][0];
        int e = matrix[n-1][m-1];
        int ans = -1;
        while(s<=e){
            int mid = s +(e-s)/2;
            if(isPossible(mid,k,matrix,n,m)){
                ans = mid;
                e = mid-1;                
            }
            else{
                s = mid +1;
            }
        }
        return ans;
    }
};