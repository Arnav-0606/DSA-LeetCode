class Solution {
public:
    int lengthOfLongestSubstring(string str) {
        set<int>s;
        int n = str.size();
        int i=0;
        int j =0;
        int ans =0;
        while(j<n){
            if(s.find(str[j])!=s.end()){
                while(str[i]!=str[j]){
                    s.erase(str[i]);
                    i++;
                }
                i++;
            }
            s.insert(str[j]);
            ans = max(ans,j-i+1);
            j++;
        }
        return ans;
        
    }
};