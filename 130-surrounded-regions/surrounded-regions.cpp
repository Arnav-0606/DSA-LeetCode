class Solution {
public:
    int dx[4] = {-1,0,1,0};
    int dy[4] = {0,1,0,-1};

    void f(int i,int j,auto &vis,auto &board,int n,int m){
        if(i<0 || i>=n || j<0 || j>=m) return;
        if(vis[i][j] || board[i][j]=='X') return;

        vis[i][j] = true;

        for(int k=0;k<4;k++){
            f(i+dx[k], j+dy[k], vis, board, n, m);
        }
    }

    void dfs(int i,int j,auto &vis,auto &board,int n,int m){
        if(i<0 || i>=n || j<0 || j>=m) return;
        if(vis[i][j] || board[i][j]=='X') return;

        vis[i][j] = true;
        board[i][j] = 'X';

        for(int k=0;k<4;k++){
            dfs(i+dx[k], j+dy[k], vis, board, n, m);
        }
    }

    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        vector<vector<bool>> vis(n, vector<bool>(m,false));

        for(int i=0;i<n;i++)
            if(board[i][0]=='O' && !vis[i][0])
                f(i,0,vis,board,n,m);
        for(int i=0;i<n;i++)
            if(board[i][m-1]=='O' && !vis[i][m-1])
                f(i,m-1,vis,board,n,m);
        for(int j=0;j<m;j++)
            if(board[0][j]=='O' && !vis[0][j])
                f(0,j,vis,board,n,m);
        for(int j=0;j<m;j++)
            if(board[n-1][j]=='O' && !vis[n-1][j])
                f(n-1,j,vis,board,n,m);

        for(int i=1;i<n-1;i++){
            for(int j=1;j<m-1;j++){
                if(board[i][j]=='O' && !vis[i][j]){
                    dfs(i,j,vis,board,n,m);
                }
            }
        }
    }
};