class Solution {
public:
    double minPrice(vector<int>& prices, vector<int>& discounts) {
        sort(prices.begin(),prices.end(),greater<int>());
        sort(discounts.begin(),discounts.end(),greater<int>());
        double ans =0;
        int t = min(prices.size(),discounts.size());
        for(int i=0;i<t;i++){
           ans += ((0.01*discounts[i])*(prices[i]));
        }
        return accumulate(prices.begin(),prices.end(),0.0) - ans;
    }
};