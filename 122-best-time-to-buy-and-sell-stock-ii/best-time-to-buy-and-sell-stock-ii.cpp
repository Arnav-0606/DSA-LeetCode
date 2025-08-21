class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int a = 0;
        int b = - prices[0];
        for(int i =1;i<n;i++){
            int c = max(a,prices[i]+b);
            int d = max(b,-prices[i]+a);
            a = c;
            b =d;
        }
        return a;
    }
};