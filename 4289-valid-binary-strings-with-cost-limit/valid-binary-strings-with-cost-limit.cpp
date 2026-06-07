class Solution {
public:
    bool checkCons(string &s){
        char last = s[0];
        for(int i=1;i<s.size();i++){
            if(s[i]=='1' and last=='1'){
                return false;
            }
            last = s[i];
        }
        return true;

    }
    vector<string> generateValidStrings(int n, int k) {
        vector<string>ans;
        for(int i=0;i<(1<<n);i++){
            string s = "";
            int cost =0;
            for(int j=0;j<n;j++){
                if((i>>j)&1){
                    s = '1'+s;
                    cost += (n-j-1);
                }
                else{
                    s = '0'+s;
                }
            }
            if(cost<=k){
                if(checkCons(s)){
                    ans.push_back(s);
                }
            }
        }
        return ans;
        
    }
};