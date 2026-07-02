class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        vector<int>mp(26,0);
        int mx = 0;
        int ans = 0;
        int i=0,j=0;
        while(j<n){
            mp[s[j]-'A']++;
            mx = max(mx,mp[s[j]-'A']);
            while((j-i+1)-mx >k){
                mp[s[i]-'A']--;
                i++;
            }
            ans = max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};