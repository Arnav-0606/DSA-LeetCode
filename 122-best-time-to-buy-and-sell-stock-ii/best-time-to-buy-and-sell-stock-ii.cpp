class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int ans = 0;
        int mn_pr = prices[0];
        for(int i =1;i<n;i++){
            if(prices[i]>mn_pr){
                ans += prices[i]-mn_pr;
                mn_pr = prices[i];
            }
            else{
            mn_pr = min(mn_pr,prices[i]);
            }
        }
        return ans;
    }
};