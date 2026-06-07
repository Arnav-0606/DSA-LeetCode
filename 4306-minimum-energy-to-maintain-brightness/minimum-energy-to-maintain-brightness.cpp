class Solution {
public:
    long long minEnergy(int n, int brightness, vector<vector<int>>& intervals) {
        int sz = intervals.size();
        int bulbs = (brightness+2)/3;
        int time = 0;
        sort(intervals.begin(),intervals.end());
        int s = intervals[0][0];
        int e = intervals[0][1];
        for(int i=1;i<sz;i++){
            auto t= intervals[i];
            int st = t[0],end=t[1];
            if(st>e){
                time += (e-s+1);
                s = st;
                e = end;
            }
            else{
                e = max(end,e);
            }
        }
        time += (e-s+1);
        return 1LL*time*bulbs;
    }
};