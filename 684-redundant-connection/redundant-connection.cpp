class disjointSet{
  vector<int>par;
  vector<int>rank;
  public:
    disjointSet(int n){
      par.resize(n+1);
      rank.resize(n+1);
    }

    void createSet(int x){
      par[x] = x;
      rank[x] = 0;
    }
    int findSet(int x){
      if(par[x]==x){
        return x;
      }
      return par[x] = findSet(par[x]);
    }

    void unionSet(int x,int y){
      int lx = findSet(x);
      int ly = findSet(y);
      if(lx!=ly){
        if(rank[lx]==rank[ly]){
          rank[lx]++;
        }
        if(rank[lx] > rank[ly]){
          par[ly] = lx;
        }
        else{
          par[lx] = ly;
        }
      }
    }
};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        disjointSet ds(1000);
        vector<int>cr(1e3+1,-1);
        vector<int>ans;
        for(auto t:edges){
            int u = t[0];
            int v = t[1];
            if(cr[u]==-1){
                ds.createSet(u);
                cr[u] = 1;
            }
            if(cr[v]==-1){
                ds.createSet(v);
                cr[v] = 1;
            }
            if(ds.findSet(u)!=ds.findSet(v)){
                ds.unionSet(u,v);
            }
            else{
                ans = {u,v};
            }
        }
        return ans;
        
    }
};