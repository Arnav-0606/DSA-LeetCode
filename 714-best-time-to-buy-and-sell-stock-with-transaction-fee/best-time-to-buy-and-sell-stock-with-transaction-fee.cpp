class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        int n0 = 0, n1=0;
        for(int i=n-1;i>=0;i--){
            int c0 = max(-prices[i]+n1,n0);
            int c1 = max(prices[i]-fee+n0,n1);
            n0 = c0;
            n1 = c1;
        }
        return n0;
        
    }
};