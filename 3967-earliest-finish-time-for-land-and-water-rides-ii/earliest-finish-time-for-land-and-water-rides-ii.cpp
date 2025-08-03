class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int n = landStartTime.size();
        int m = waterStartTime.size();
        int ans = INT_MAX;
        int lbw = INT_MAX;
        int wbl = INT_MAX;
        for(int i=0;i<n;i++){
            lbw = min(lbw,landStartTime[i]+landDuration[i]);
        }
        for(int i=0;i<m;i++){
            wbl = min(wbl,waterStartTime[i]+waterDuration[i]);
        }
        for(int i=0;i<m;i++){
            ans = min(max(lbw,waterStartTime[i])+waterDuration[i],ans);       
        }
        for(int i=0;i<n;i++){
            ans = min(max(wbl,landStartTime[i])+landDuration[i],ans);
        }
        return ans;        
    }
};
