class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.size();
        if(n==1) return 0;
        vector<int>a(n);
        vector<int>b(n);
        int ac=0,bc=0,ans=n;
        for(int i=0;i<n;i++){
            b[i] = bc;
            if(s[i]=='b') bc++;
        }
        if(bc==n) return 0;
        for(int i=n-1;i>=0;i--){
            a[i] = ac;
            if(s[i]=='a') ac++;
        }
        if(ac==n) return 0;
        for(int i=0;i<n;i++){
            if(s[i]=='a') ans = min(ans,a[i]+b[i]);
        }
        ans=min(ans,n-ac);
        ans = min(ans,n-bc);
        return ans;

    }
};