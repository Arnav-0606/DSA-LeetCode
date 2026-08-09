class Solution {
public:
    long long weightedSum(vector<int>& parent, vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>adj(n);
        vector<int>depth(n,-1);
        for(int i=1;i<n;i++){
            adj[parent[i]].push_back(i);
        }
        depth[0]=1;
        int h = 1;
        queue<int>q;
        q.push(0);
        while(!q.empty()){
            int u =q.front();
            q.pop();
            for(auto v:adj[u]){
                if(depth[v]==-1){
                    depth[v] = depth[u]+1;
                    q.push(v);
                    h = max(h,depth[v]);
                }
            }
        }
        long long ans = 0;
        for(int i=0;i<n;i++){
            ans += (1LL*nums[i])*(h-depth[i]+1);
        }
        return ans;


    }
};