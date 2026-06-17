class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int cnt =0;
        int n = numCourses;
        vector<int>indeg(n,0);
        unordered_map<int,vector<int>>adj;
        for(auto &t:prerequisites){
            int u = t[0];
            int v = t[1];
            adj[v].push_back(u);
            indeg[u]++;
        }
        queue<int>q;
        for(int i=0;i<n;i++){
            if(indeg[i]==0){
                q.push(i);
                cnt++;
            }
        }
        while(!q.empty()){
            int f = q.front();
            q.pop();
            for(auto & ngb :adj[f]){
                indeg[ngb]--;
                if(indeg[ngb]==0){
                    cnt++;
                    q.push(ngb);
                }
            }
        }
        return (cnt==numCourses);
        
    }
};