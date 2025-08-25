class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        stack<int>s;
        int n = heights.size();
        vector<int>ans(n);
        for(int i=n-1;i>=0;i--){
            int cnt =0;
            while(!s.empty() and heights[s.top()]<heights[i]){
                cnt++;
                s.pop();
            }
            if(!s.empty()) cnt++;
            ans[i] = cnt;
            s.push(i);
        }
        return ans;
    }
};