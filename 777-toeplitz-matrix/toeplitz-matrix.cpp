class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& mat) {
        int rows = mat.size();
        int cols = mat[0].size();
        if(rows<=1 or cols<=1) return true;
        for(int i=1;i<rows;i++){
            for(int j=1;j<cols;j++){
                if(mat[i][j]!= mat[i-1][j-1]) return false;
            }
        }
        return true;
    }
};