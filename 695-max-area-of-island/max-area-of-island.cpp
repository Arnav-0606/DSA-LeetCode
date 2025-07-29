class Solution {
public:
    int dx[4] = {-1,0,1,0};
    int dy[4] = {0,1,0,-1};
    int dfs(vector<vector<int>>& grid,int i,int j,int n,int m){
        if(i==-1 or i == n or j ==-1 or j == m or grid[i][j]==0 or grid[i][j]==-1){
            return 0;
        }
        grid[i][j] = -1;
        int ans =0;
        for(int k =0;k<4;k++){
            ans += dfs(grid,i+dx[k],j+dy[k],n,m);
        }
        return ans+1;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea = 0;
        int n = grid.size();
        int m = grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    maxArea = max(maxArea,dfs(grid,i,j,n,m));
                }
                grid[i][j] = -1;
            }
        }
        return maxArea;        
    }
};