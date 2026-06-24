class Solution {
public:
    int dx[4] = {-1,0,1,0};
    int dy[4] = {0,1,0,-1};
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>>minEffort(n,vector<int>(m,INT_MAX));
        priority_queue<
        tuple<int,int,int>,
        vector<tuple<int,int,int>>,
        greater<tuple<int,int,int>>
        >pq;
        pq.push({0,0,0});
        minEffort[0][0] = 0;
        while(!pq.empty()){
            auto [d,i,j] = pq.top();
            pq.pop();
            if(d > minEffort[i][j]) continue;
            for(int k=0;k<4;k++){
                int a = i+dx[k];
                int b = j + dy[k];
                if(a<0 or a>=n or b<0 or b>=m) continue;
                if(max(d,abs(heights[i][j]-heights[a][b]))< minEffort[a][b]){
                    minEffort[a][b] = max(d,abs(heights[i][j]-heights[a][b]));
                    pq.push({minEffort[a][b],a,b});
                }
            }
        }
        return minEffort[n-1][m-1];

    }
};