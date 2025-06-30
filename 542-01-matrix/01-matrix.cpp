class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        vector<vector<int>> dis(m, vector<int>(n, -1));
        queue<pair<int, int>> q;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(mat[i][j]==0){
                    q.push({i, j});
                    dis[i][j]=0;
                }
            }
        }

        int dx[]={0, 0, 1, -1};
        int dy[]={1, -1, 0, 0};

        while(!q.empty()){
            auto [i, j] = q.front();
            q.pop();

            for(int k=0; k<4; k++){
                int ii = i + dx[k];
                int jj = j + dy[k];

                if(ii>=0 and ii<m and jj>=0 and jj<n and dis[ii][jj]==-1){
                    dis[ii][jj] = dis[i][j] + 1;
                    q.push({ii, jj});
                }
            }
        }

        return dis;

    }
};