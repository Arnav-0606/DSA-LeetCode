class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        if(m==1 and n==1) return 0;
        int vis[40][40][1601] = {0};
        vis[0][0][k] = 1;
        int steps = 1;
        int dx[4] = {-1,0,1,0};
        int dy[4] = {0,1,0,-1};
        queue<tuple<int,int,int>>q;
        q.push({0,0,k});
        q.push({-1,-1,-1});
        while(!q.empty()){
            auto [i,j,e]= q.front();
            q.pop();
            if(i==-1){
                steps++;
                if(!q.empty()){
                    q.push({-1,-1,-1});
                    continue;
                }
            }
            for(int k=0;k<4;k++){
                int a = i + dx[k];
                int b = j + dy[k];
                if(a<0 or a>=m or b<0 or b>=n) continue;
                if(a==m-1 and b==n-1) return steps;
                if(grid[a][b] and e>0 and !vis[a][b][e-1]){
                    q.push({a,b,e-1});
                    vis[a][b][e-1] = 1;
                }
                else if(grid[a][b]==0 and !vis[a][b][e]){
                    q.push({a,b,e});
                    vis[a][b][e] = 1;
                }
            }
        }
        return -1;
    }
};