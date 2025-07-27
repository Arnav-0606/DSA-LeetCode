class Solution {
public:
    long long countLCT(string s){
        long long l = 0;
        long long lc =0;
        long long lct =0;
        for(char c:s){
            if(c=='L') l++;
            else if(c == 'C') lc+=l;
            else if(c == 'T') lct += lc;
        }
        return lct;
    }
    long long numOfSubsequences(string s) {
        int n = s.size();
        long long to = countLCT(s);
        long long t1 = countLCT("L" + s);
        long long t2 = countLCT(s+"T");
        long long ans = max({to,t1,t2});
        vector<long long>suf(n+1,0);
        long long t =0;
        for(int i =n-1;i>=0;i--){
            suf[i] =t;
            if(s[i]=='T') t++;
        }
        long long l=0;
        long long curr =0;
        for(int i =0;i<=n;i++){
            if(i<n and s[i]=='L') l++;
            curr = max(curr,l*suf[i]);
        }    
        return max(ans,curr+to);
    }
};