class Solution {
public:
    int dfs(vector<vector<int>>& grid,vector<vector<int>>&visited,int i,int j,int n,int m,int k){
        //base case
        if(i<0 or i >= n or j >= m or j<0 or visited[i][j] or grid[i][j]==0){
            return 0;
        }
        visited[i][j] =1;
        int sum = (grid[i][j])%k;
        sum += (dfs(grid, visited, i + 1, j, n, m,k))%k;
        sum += (dfs(grid, visited, i - 1, j, n, m,k))%k;
        sum += (dfs(grid, visited, i, j + 1, n, m,k))%k;
        sum += (dfs(grid, visited, i, j - 1, n, m,k))%k;
        return sum;
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        int cnt =0;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>visited(n,vector<int>(m,0));
        for(int i =0;i<n;i++){
            for(int j =0;j<m;j++){
                if(!visited[i][j] and grid[i][j]!=0){
                    int sum = dfs(grid,visited,i,j,n,m,k);
                    if(sum%k==0) cnt++;
                }
                visited[i][j] =1;
            }
        }
        return cnt;
    }
};