class Solution {
public:
    int lengthOfLastWord(string s) {
        int i = s.size()-1;
        int ans =0;
        while(i>=0 and s[i]==' '){
            i--;
        }
        while(i>=0 and s[i]!=' '){
            ans++;
            i--;
       }
       return ans;
    }
};