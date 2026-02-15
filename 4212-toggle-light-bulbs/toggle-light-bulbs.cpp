class Solution {
public:
    vector<int> toggleLightBulbs(vector<int>& bulbs) {
        bool a[101]={0};
        int n = bulbs.size();
        for(int i=0;i<n;i++){
            a[bulbs[i]] = 1 - a[bulbs[i]];
        }
        vector<int>v;
        for(int i=1;i<101;i++){
            if(a[i]) v.push_back(i);
        }
        return v;
        
    }
};