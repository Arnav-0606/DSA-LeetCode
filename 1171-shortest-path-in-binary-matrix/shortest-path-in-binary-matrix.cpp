class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int dx[] = {-1,-1,-1,0,1,1,1,0};
        int dy[] = {-1,0,1,1,1,0,-1,-1};
        int n = grid.size();
        if(grid[0][0]==1) return -1;
        vector<vector<bool>>vis(n,vector<bool>(n,false));
        queue<pair<int,int>>q;
        int l = 1;
        vis[0][0] = true;
        q.push({0,0});
        q.push({-1,-1});
        while(!q.empty()){
            auto [i,j] = q.front();
            q.pop();
            if(i==-1){
                if(!q.empty()){
                    q.push({-1,-1});
                    l++;
                }
            }
            if(i==n-1 and j==n-1){
                return l;
            }
            for(int k=0;k<8;k++){
                int a = i + dx[k];
                int b = j + dy[k];
                if(a>=n or b>=n or a<0 or b<0) continue;
                if(!vis[a][b]){
                    vis[a][b] = true;
                    if(grid[a][b]==0){
                        q.push({a,b});

                    }
                }
            }
        }
        return -1;


    }
};