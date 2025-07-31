class Solution {
public:
    int dx[4] = {-1,0,1,0};
    int dy[4] = {0,1,0,-1};
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        int ans =0;
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    q.push({i,j});
                }
            }
        }
        if(q.size()==0 or q.size()==n*n) return -1;
        q.push({-1,-1});
        while(!q.empty()){
            auto[i,j] = q.front();
            q.pop();
            if(i==-1){
                if(!q.empty())q.push({-1,-1});
                ans++;
                continue;
            }
            for(int k=0;k<4;k++){
                int di = i + dx[k];
                int dj = j + dy[k];
                if(di>=0 and di<n and dj>=0 and dj<n and grid[di][dj]==0){
                    q.push({di,dj});
                    grid[di][dj]=1;
                }
            }
        }
        return ans==0 ? -1 : ans-1;
    }
};