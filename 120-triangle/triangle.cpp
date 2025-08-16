class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int row = triangle.size()-2;
        for(int i =row;i>=0;i--){
            for(int j = i;j>=0;j--){
                triangle[i][j] += min(triangle[i+1][j],triangle[i+1][j+1]);
            }
        }
        return triangle[0][0];


        
    }
};