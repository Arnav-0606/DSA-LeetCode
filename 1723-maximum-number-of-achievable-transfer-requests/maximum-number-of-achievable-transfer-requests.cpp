class Solution {
public:
    int ans = 0;
    void f(int i,int curr,vector<int>netChange,vector<vector<int>>&reqs){
        if(i==reqs.size()){
        for(int i =0;i<netChange.size();i++){
            if(netChange[i]!=0) {
                return;
            }
        }
        ans = max(curr,ans);
        return;
        }
        f(i+1,curr,netChange,reqs);
        vector<int>t=reqs[i];
        netChange[t[0]]--;
        netChange[t[1]]++;
        f(i+1,curr+1,netChange,reqs);
        // netChange[t[0]]++;
        // netChange[t[1]]--;       
    }
    int maximumRequests(int n, vector<vector<int>>& requests) {
        vector<int>netChange(n,0);
        f(0,0,netChange,requests);
        return ans;
    }
};