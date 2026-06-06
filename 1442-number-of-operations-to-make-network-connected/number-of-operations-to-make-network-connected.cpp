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
    int makeConnected(int n, vector<vector<int>>& connections) {
        disjointSet ds(n);
        for(int i=0;i<n;i++){
            ds.createSet(i);
        }  
        int extraCables = 0;
        for(auto t:connections){
            int u = t[0];
            int v = t[1];
            if(ds.findSet(u) == ds.findSet(v)){
                extraCables++;
            }
            else{
                ds.unionSet(u,v);
            }
        }
        int requiredCables = 0;
        for(int i=1;i<n;i++){
            if(ds.findSet(0)!=ds.findSet(i)){
                ds.unionSet(0,i);
                requiredCables++;
            }
        }
        if(extraCables<requiredCables) return -1;
        return requiredCables;

    }
};