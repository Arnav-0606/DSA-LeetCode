class Solution {
public:
    int maxRepOpt1(string text) {
        int n = text.size();
        if(n==1) return 1;
        int ans = 0;
        vector<pair<char,int>>pr(n),suf(n);
        pr[0] = {'#',0};
        suf[n-1] = {'#',0};
        char c = text[0];
        int cnt = 1;
        vector<int>mp(26,0);
        mp[c-'a']++;
        for(int i=1;i<n;i++){
            pr[i] = {c,cnt};
            mp[text[i]-'a']++;
            if(text[i]==c){
                cnt++;
            }
            else{
                c = text[i];
                cnt = 1;
            }
            
        }
        c = text[n-1];
        cnt = 1;
        for(int i=n-2;i>=0;i--){
            suf[i] = {c,cnt};
            if(text[i]==c){
                cnt++;
            }
            else{
                c = text[i];
                cnt = 1;
            }
        }
        for(int i=0;i<n;i++){
            char c = text[i];
            char c1 = pr[i].first;
            int f1 = pr[i].second;
            char c2 = suf[i].first;
            int f2 = suf[i].second;
            if(i!=0){
            if(f1==mp[c1-'a']){
                ans = max(ans,f1);
            }
            else if(mp[c1-'a']-f1){
                ans = max(ans,f1+1);
            }
            }
            if(i!=n-1){
            if(mp[c2-'a']==f2){
                ans = max(ans,f2);                
            }
            else if(mp[c2-'a']-f2){
                ans = max(ans,f2+1);
            }
            }
            if(i>0 and i<n-1){
            if(c1==c2 and c!=c1){
                int f = f1+f2;
                if(mp[c1-'a']==f){
                ans = max(ans,f);                
                }
                else if(mp[c1-'a']-f){
                    ans = max(ans,f+1);
                }

            }
            }

        }
        return ans;

    }
};