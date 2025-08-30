class Solution {
public:
    int getLeastFrequentDigit(int n) {
        int minCount = INT_MAX;
        int minNum = INT_MAX;
        unordered_map<int,int>mp;
        int c = n;
        while(n){
            mp[n%10]++;
            n/=10;
        }
        for(auto [k,v]:mp){
            if(v==minCount){
                minNum = min(minNum,k);
            }
            if(v<minCount){
                minCount =v;
                minNum = k;
            }
        }
        return minNum;       
    }
};