class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>>ans;
        stack<vector<int>>s;
        s.push(intervals[0]);
        for(int i=1;i<intervals.size();i++){
            vector<int>curr = intervals[i];
            vector<int>last = s.top();
            if(curr[0]<=last[1]){
                s.pop();
                s.push({last[0],max(last[1],curr[1])});
            }
            else{
                s.push(curr);
            }
        } 
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
        return ans;
    }
};