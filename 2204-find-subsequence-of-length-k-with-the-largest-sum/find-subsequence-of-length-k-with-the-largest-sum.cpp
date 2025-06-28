class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        for(int i=0;i<k;i++){
            pq.push({nums[i],i});
        }
        for(int i=k;i<n;i++){
            if(pq.top().first<nums[i]){
                pq.pop();
                pq.push({nums[i],i});
            }
        }
        vector<int>ans;
        priority_queue<int,vector<int>,greater<int>>pq2;
        while(!pq.empty()){
            pq2.push(pq.top().second);
            pq.pop();
        }
        while(!pq2.empty()){
            ans.push_back(nums[pq2.top()]);
            pq2.pop();
        }
        return ans;
    }
};