class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>>mat(n,vector<int>(n,0));
        int cnt = 1;
        int left =0;
        int right = n-1;
        int top =0;
        int bottom = n-1;
        while(left <= right and top <= bottom){
        for(int i=left;i<=right;i++){
            mat[top][i] = cnt++;
        }
        top++;
        for(int i = top;i<=bottom;i++){
            mat[i][right] = cnt++;
        }
        right--;
        for(int i = right;i>=left;i--){
            mat[bottom][i] = cnt++;
        }
        bottom--;
        for(int i = bottom;i>=top;i--){
            mat[i][left] = cnt++;
        }
        left++;
        }
        return mat;
    }
};