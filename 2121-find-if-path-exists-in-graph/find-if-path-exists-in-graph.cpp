class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>>adj(n);
        vector<int>vis(n,0);
        for(vector<int>edge:edges){
            adj[edge[1]].push_back(edge[0]);
            adj[edge[0]].push_back(edge[1]);
        }
        queue<int>q;
        q.push(source);
        vis[source]=1;
        while(!q.empty()){
            int f = q.front();
            if(f==destination) return true;
            for(int ngb:adj[f]){
                if(!vis[ngb]) {
                    q.push(ngb);
                    vis[ngb]=1;
                }
            }
            q.pop();
        }
        return false;       
    }
};