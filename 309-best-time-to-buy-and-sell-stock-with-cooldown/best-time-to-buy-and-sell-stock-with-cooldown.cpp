class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int p10=0,p11=0,p20=0;
        for(int i=n-1;i>=0;i--){
            int c0 = max(-prices[i] + p11,p10);
            int c1 = max(prices[i]+p20,p11);
            p20 = p10;
            p10 = c0;
            p11 = c1;
        }
        return p10;
    }
};
