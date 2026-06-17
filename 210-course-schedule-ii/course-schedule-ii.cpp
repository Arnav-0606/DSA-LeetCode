class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        int cnt=0;
        vector<int>indeg(n,0);
        unordered_map<int,vector<int>>adj;
        vector<int>ans;
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
                ans.push_back(i);
            }
        }
        while(!q.empty()){
            int f = q.front();
            q.pop();
            for(auto & ngb :adj[f]){
                indeg[ngb]--;
                if(indeg[ngb]==0){
                    cnt++;
                    ans.push_back(ngb);
                    q.push(ngb);
                }
            }
        }
        if(n==cnt) return ans;
        return {};
    }
};