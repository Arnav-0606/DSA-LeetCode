class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>color(n,-1);
        int k =0;
        for(int i=0;i<n;i++){
            if(color[i]==-1){
                queue<int>q;
                q.push(i);
                color[i] = k;
                q.push(-1);
                while(!q.empty()){
                    int f = q.front();
                    q.pop();
                    if(f==-1){
                        if(!q.empty())q.push(-1);
                        k = 1-k;
                        continue;
                    }
                    for(int ngb:graph[f]){
                        if(color[ngb]==-1){
                            color[ngb] = 1-k;
                            q.push(ngb);
                        }
                        else{
                            if(color[ngb]==color[f]){
                                return false;
                            }
                        }
                    }
                }
            }
        }
        return true;   
    }
};