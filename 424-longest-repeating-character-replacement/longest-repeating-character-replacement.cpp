class Solution {
public:
    bool f(int ws,int k,string &s){
        int cnt =0;
        int mx = INT_MIN;
        int mn = INT_MAX;
        int n = s.size();
        vector<int>mp(26,0);
        for(int i=0;i<ws;i++){
            mp[s[i]-'A']++;
            mx = max(mx,mp[s[i]-'A']);
        }
        if(ws-mx<=k) return true;
        for(int i=ws;i<n;i++){
            mp[s[i]-'A']++;
            mp[s[i-ws]-'A']--;
            mx = INT_MIN;
            for(int i=0;i<26;i++){
                mx = max(mp[i],mx);
            }
            if(ws-mx<=k) return true;
        }
        return false;
    }
    int characterReplacement(string s, int k) {
        int n = s.size();
        int lb = 1;
        int ub = n;
        int ans =-1;
        while(lb<=ub){
            int mid = (ub-lb)/2 +lb;
            if(f(mid,k,s)){
                ans = mid;
                lb = mid+1;
            }
            else{
                ub = mid-1;
            }
        }
        return ans;
    }
};