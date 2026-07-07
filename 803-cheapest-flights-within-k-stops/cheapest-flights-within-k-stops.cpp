class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int>dist(n,1e9);
        dist[src] = 0;
        for(int i=0;i<=k;i++){
            vector<int>temp = dist;
            for(auto &fl:flights){
                int u = fl[0];
                int v = fl[1];
                int w = fl[2];
                if(dist[u]!= 1e9 and dist[v]>dist[u]+w){
                    temp[v] = min(temp[v],dist[u]+w);
                }
            }
            dist = temp;
        }
        return (dist[dst]==1e9) ?-1:dist[dst];
        
    }
};