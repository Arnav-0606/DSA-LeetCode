class Solution {
public:
    vector<int> luckyNumbers(vector<vector<int>>& mat) {
        int rows = mat.size();
        int cols = mat[0].size();
        vector<int> rowMin(rows, INT_MAX);
        vector<int> colMax(cols, INT_MIN);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                rowMin[i] = min(rowMin[i], mat[i][j]);
                colMax[j] = max(colMax[j], mat[i][j]);
            }
        }
        vector<int> ans;
        for (int i = 0; i<rows;++i) {
            for (int j = 0;j<cols; ++j) {
                if (mat[i][j] == rowMin[i] && mat[i][j] == colMax[j]) {
                    ans.push_back(mat[i][j]);
                }
            }
        }
        return ans;
    }
};
