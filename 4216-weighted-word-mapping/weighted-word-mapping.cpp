class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans = "";
        for(string s:words){
            int sum = 0;
            for(char c:s){
                sum += weights[c-'a'];
            }
            sum %=26;
            ans += (25-sum+'a');
        }
        return ans;
    }
};