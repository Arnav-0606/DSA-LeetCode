class Solution {
public:
    int maxCapacity(vector<int>& cost, vector<int>& capacity, int budget) {
        int n = cost.size();
        vector<pair<int,int>>v;
        for(int i=0;i<n;i++){
            v.push_back({cost[i],i});
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            if(cost[i]<budget) ans = max(ans,capacity[i]);
        }
        sort(v.begin(),v.end());
        vector<int>pmc(n);
        pmc[0] = capacity[v[0].second];
        int mx = pmc[0];
        for(int i=1;i<n;i++){
            mx = max(mx,capacity[v[i].second]);
            pmc[i] = mx;
        }
        vector<int>c(n);
        for(int i=0;i<n;i++){
            c[i] = v[i].first;

        }
         for(int i=1;i<n;i++){
            int rem = budget-c[i]-1;
            int idx = upper_bound(c.begin(),c.begin()+i,rem) - c.begin()-1;
            if(idx!=i and idx>=0){
                ans = max(ans,pmc[idx]+capacity[v[i].second]);
            }
        }
        return ans;
    }
    
};