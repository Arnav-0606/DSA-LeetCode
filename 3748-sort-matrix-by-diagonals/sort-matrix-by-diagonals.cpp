class Solution {
public:
    void sortDiagonal(vector<vector<int>>&grid,int i,int j,int n,int m,int c){
        vector<int>temp;
        int a =i;
        int b =j;
        while(i<n and j<m){
            temp.push_back(grid[i][j]);
            i++;
            j++;
        }
        sort(temp.begin(),temp.end());
        if(c==0){
            reverse(temp.begin(),temp.end());
        }
        for(int k =0;k<temp.size();k++){
            grid[a+k][b+k] = temp[k];
        }
    }
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int c =0;
        for(int i=0;i<n;i++){
            sortDiagonal(grid,i,0,n,m,c);
        }
        c = 1;
        for(int i =1;i<m;i++){
            sortDiagonal(grid,0,i,n,m,c);
        }
        return grid;
    }
};