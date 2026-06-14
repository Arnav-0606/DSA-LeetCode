class Solution {
public:
    long long maxRatings(vector<vector<int>>& units) {
        int n = units.size();
        int m = units[0].size();
        int mnfrst = INT_MAX;
        long long sum =0;
        long long sum2 =0;
        for(int i=0;i<n;i++){
            sort(units[i].begin(),units[i].end());
            mnfrst = min(mnfrst,units[i][0]);
            sum += units[i][0];
            if(m>1) sum2 += units[i][1];
        }
        if(n==1) return mnfrst;
        if(m==1){
            return sum;
        }
        long long ans = INT_MIN;
        for(int i=0;i<n;i++){
            ans = max(ans,sum2-units[i][1]+mnfrst);
        }
        return ans;
        
    }
};