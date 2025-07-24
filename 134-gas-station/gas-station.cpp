class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int sum =0;
        int ans =0;
        int net =0;
        int n = gas.size();
        for(int i=0;i<n;i++){
            net += (gas[i]-cost[i]);
            sum+= gas[i]-cost[i];
            if(sum<0){
                ans = i+1;
                sum =0;
            }
        }
        if(net<0) return -1;
        return ans;
    }
};