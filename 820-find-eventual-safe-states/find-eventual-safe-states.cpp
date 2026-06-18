class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        unordered_map<int,vector<int>>adj;
        vector<int>indeg(n,0);
        for(int i=0;i<n;i++){
            for(int &ngb:graph[i]){
                adj[ngb].push_back(i);
                indeg[i]++;
            }
        }
        vector<int>ans;
        queue<int>q;
        for(int i=0;i<n;i++){
            if(indeg[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int f = q.front();
            q.pop();
            ans.push_back(f);
            for(int &ngb:adj[f]){
                indeg[ngb]--;
                if(indeg[ngb]==0){
                    q.push(ngb);
                }
            }

        }
        sort(ans.begin(),ans.end());

        return ans;        
    }
};