class Solution {
public:
    int n;
    vector<int>v;
    int last;
    Solution(vector<int>& w) {
        n = w.size();
        v.resize(n);
        int sm = -1;
        for(int i=0;i<n;i++){
            sm += w[i];
            v[i] = sm;
        }
        last = v[n-1];
    }

    int pickIndex() {
        int num = (rand()%(last+1));
        return lower_bound(v.begin(),v.end(),num)-v.begin();    
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */