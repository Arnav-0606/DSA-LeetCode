class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.size();
        vector<int>a(n);
        vector<int>b(n);
        int ac=0,bc=0,ans=n;
        for(int i=0;i<n;i++){
            b[i] = bc;
            if(s[i]=='b') bc++;
        }
        for(int i=n-1;i>=0;i--){
            a[i] = ac;
            if(s[i]=='a') ac++;
        }
        for(int i=0;i<n;i++){
            if(s[i]=='a') ans = min(ans,a[i]+b[i]);
        }
        ans=min(ans,n-ac);
        ans = min(ans,n-bc);
        return ans;

    }
};