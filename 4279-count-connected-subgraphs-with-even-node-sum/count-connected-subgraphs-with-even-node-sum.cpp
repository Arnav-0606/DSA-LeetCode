class Solution {
public:
    int bfs(set<int>&s,int k,auto & adj){
        int cnt = 0;
        vector<int>vis(k,0);
        queue<int>q;
        q.push(*s.begin());
        vis[*s.begin()] = 1;
        cnt++;
        while(!q.empty()){
            int t = q.front();
            q.pop();
            for(auto v : adj[t]){
                if(s.find(v)!=s.end()){
                    if(!vis[v]){
                        vis[v] = 1;
                        cnt++;
                        q.push(v);
                    }
                }
            }
        }
        return cnt;

    }
    int evenSumSubgraphs(vector<int>& nums, vector<vector<int>>& edges) {
        int k = nums.size();
        vector<vector<int>>adj(k);
        for(auto t:edges){
            int u = t[0];
            int v = t[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int ans = 0;
        for(int i=1;i<(1<<k);i++){
            int sum = 0;
            set<int>s;
            for(int j =0;j<k;j++){
                if((i>>j)&1){
                    s.insert(j);
                    sum += nums[j];
                }
            }
            int cnt = bfs(s,k,adj);
            if((cnt==s.size()) and !(sum&1)) ans++;
        }
        return ans;
        
    }
};