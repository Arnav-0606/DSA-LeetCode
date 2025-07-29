class Solution {
public:
    int dx[4] = {-1,0,1,0};
    int dy[4] = {0,1,0,-1};
    int dfs(vector<vector<int>>& grid,vector<vector<bool>>&vis,int i,int j,int n,int m){
        if(i==-1 or i == n or j ==-1 or j == m or grid[i][j]==0 or vis[i][j]){
            return 0;
        }
        vis[i][j] = true;
        int ans =0;
        for(int k =0;k<4;k++){
            ans += dfs(grid,vis,i+dx[k],j+dy[k],n,m);
        }
        return ans+1;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea = 0;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] and grid[i][j]==1){
                    maxArea = max(maxArea,dfs(grid,vis,i,j,n,m));
                }
                vis[i][j] = true;
            }
        }
        return maxArea;        
    }
};