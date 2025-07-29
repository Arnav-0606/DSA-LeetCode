class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>>q;
        int ans =0;
        int n = grid.size();
        int m = grid[0].size();
        int fresh =0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
                else if(grid[i][j]==1){
                    fresh++;
                }
            }
        }
        if (fresh == 0) return 0;
        q.push({-1,-1});
        while(!q.empty()){
            auto [i,j] = q.front();
            q.pop();
            if(i == -1 && j == -1) {
                if (!q.empty()) {
                    ans++;
                    q.push({-1, -1});
                }
                continue;
            }
            int dx[4] = {-1, 0, 1, 0};
            int dy[4] = {0, 1, 0, -1};
            for (int d = 0; d < 4; d++) {
                int ni = i + dx[d], nj = j + dy[d];
                if (ni >= 0 && ni < n && nj >= 0 && nj < m && grid[ni][nj] == 1) {
                    grid[ni][nj] = 2;
                    fresh--;
                    q.push({ni, nj});
                }
            } 
        }
        return fresh==0?ans:-1;
    }
};