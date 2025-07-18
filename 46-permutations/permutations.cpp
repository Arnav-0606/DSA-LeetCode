class Solution {
public:
    vector<vector<int>>ans;
    vector<int>perm;
    int n;
    void f(vector<int>&v,int i,int bitmask){
        //base case
        if(bitmask == (1<<n)-1){
            ans.push_back(perm);
            return;
        }

        //recursive case
        for(int j=0;j<n;j++){
            if((bitmask>>j)&1){
                continue;
            }
            perm.push_back(v[j]);
            f(v,i+1,bitmask|(1<<j));
            perm.pop_back();
        }
    }
    vector<vector<int>> permute(vector<int>& v) {
        this->n = v.size();
        f(v,0,0);
        return ans;       
    }
};