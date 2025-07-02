class Solution {
public:
    int distance(vector<int>&v){
        int dis = (v[0]*v[0]) + (v[1]*v[1]);
        return dis;
        }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,int>,vector<pair<int,int>>>m;
        for(int i =0;i<k;i++){
            m.push({distance(points[i]),i});
        }
        for(int i = k;i<points.size();i++){
            int t = distance(points[i]);
            if(t < m.top().first){
                m.pop();
                m.push({t,i});
            }
        }
        vector<vector<int>>ans;
        while(!m.empty()){
            int t = m.top().second;
            m.pop();
            ans.push_back(points[t]);
        }   
        return ans;     
    }
};