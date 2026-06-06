class Solution {
public:
    vector<int> maximumMEX(vector<int>& nums) {
        int mex = 0;
        int n = nums.size();
        vector<int>occ(1e5+1,0);
        vector<int>v;
        for(int i:nums){
            occ[i]++;
        }
        while(occ[mex])mex++;
        int curr_mex = 0;
        int next_mex = mex;
        set<int>s;
        for(int i=0;i<n;i++){
            s.insert(nums[i]);
            while(s.find(curr_mex)!=s.end())curr_mex++;
            occ[nums[i]]--;
            if(occ[nums[i]]==0){
                next_mex = min(next_mex,nums[i]);
            }
             if(curr_mex == mex){
                v.push_back(curr_mex);
                s.clear();
                curr_mex = 0;
                mex = next_mex;
            }
        }
        return v;


    }
};