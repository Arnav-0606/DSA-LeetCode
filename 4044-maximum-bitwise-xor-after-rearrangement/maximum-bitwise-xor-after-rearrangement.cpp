class Solution {
public:
    string maximumXor(string s, string t) {
        int n = t.size();
        int z =0,o =0;
        string ans = t;
        for(char c:t){
            if(c=='0') z++;
            else o++;
        }
        for(int i=0;i<n;i++){
            if(s[i]=='0'){
                if(o>0){
                    ans[i] = '1';
                    o--;
                }
                else{
                    ans[i] = '0';
                    z--;
                }
            }
            else{
                if(z>0){
                    ans[i] = '1';
                    z--;
                }
                else{
                    ans[i] = '0';
                    o--;
                }

            }
        }
        return ans;
                
    }
};