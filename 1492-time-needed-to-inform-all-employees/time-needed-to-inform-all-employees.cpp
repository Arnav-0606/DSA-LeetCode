class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>>adj(n);
        for(int i=0;i<n;i++){
            if(manager[i]==-1) continue;
            adj[manager[i]].push_back(i);
        }
        queue<pair<int,int>>q;
        int maxTime =0;
        q.push({headID,0});
        while(!q.empty()){
            auto [curr,time] = q.front();
            q.pop();
            maxTime = max(maxTime,time);
            for(int ngb:adj[curr]){
                q.push({ngb,time+informTime[curr]});
            }
        }
        return maxTime;
    }
};