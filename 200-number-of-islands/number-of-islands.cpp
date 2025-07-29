class Solution {
public:
    int dx[4] = {-1,0,1,0};
    int dy[4] = {0,1,0,-1};
    void dfs(vector<vector<char>>& grid,int i,int j,int n,int m){
        if(i<0 or i >= n or j<0 or j >= m or grid[i][j]=='0'){
            return;
        }
        grid[i][j] = '0';
        for(int k =0;k<4;k++){
            dfs(grid,i+dx[k],j+dy[k],n,m);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty() or grid[0].empty()) {
            return 0;
        }
        int ans = 0;
        int n = grid.size();
        int m = grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'){
                    dfs(grid,i,j,n,m);
                    ans++;
                }
            }
        }
        return ans;
    }
};