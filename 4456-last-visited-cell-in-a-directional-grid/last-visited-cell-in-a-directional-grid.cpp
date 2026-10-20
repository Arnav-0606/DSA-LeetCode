class Solution {
public:
    vector<int> f(int a,int b,auto & vis,auto & grid){
        int dx=0,dy=0;
        int n = grid.size();
        int m = grid[0].size();
        if(grid[a][b]=='L'){
            dy--;
        }
        else if(grid[a][b]=='R'){
            dy++;
        }
        else if(grid[a][b]=='U'){
            dx--;
        }
        else{
            dx++;
        }
        int x = a+dx;
        int y = b +dy;
        if(x>=0 and x<n and y>=0 and y<m and !vis[x][y]){
            vis[x][y] =1;
            return f(x,y,vis,grid);
        }
        else return {a,b};
    }
    vector<int> lastVisitedCell(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        vis[0][0] =1;
        return f(0,0,vis,grid);
    }
};
// grid = [["R","R","R"]]