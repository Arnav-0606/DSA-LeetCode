class Solution {
public:
    int dx[4] = {0,-1,0,1};
    int dy[4] = {-1,0,1,0};
    void dfs(auto & grid,int i,int j,int n,int k,auto & mp){
        if(i<0 or i>=n or j<0 or j>=n) return;
        if(grid[i][j]!=1) return;
        grid[i][j] = k;
        mp[k]++;
        for(int u=0;u<4;u++){
            int a = i+ dx[u];
            int b = j + dy[u];
            dfs(grid,a,b,n,k,mp);
        }
    }
    int largestIsland(vector<vector<int>>& grid) {
        int k =2;
        map<int,int>mp;
        int mxArea = 0;
        int n = grid.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    dfs(grid,i,j,n,k,mp);
                    k++;
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    int ans = 0;
                    set<int>s;
                    for(int u=0;u<4;u++){
                        int a = i+ dx[u];
                        int b = j + dy[u];
                        if(a<0 or a>=n or b<0 or b>=n or grid[a][b]==0) continue;
                        if(s.count(grid[a][b])==0){
                            ans += mp[grid[a][b]];
                            s.insert(grid[a][b]);
                        }
                    }
                    mxArea = max(ans +1,mxArea);
                }
            }
        }
        for(auto [k,v]:mp){
            mxArea = max(mxArea,v);
        }
        return mxArea;

        
    }
};