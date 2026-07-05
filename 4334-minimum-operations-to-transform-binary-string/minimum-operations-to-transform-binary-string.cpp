class Solution {
public:
    int minOperations(string s1, string s2) {
        int ans =0;
        int n = s1.size();
        if(n==1){
            if(s1[0]=='1' and s2[0]=='0') return -1;
        }
        for(int i=0;i<n;i++){
        if(s1[i]=='1' and s2[i]=='0'){
            if(i==0){
                if(s1[i+1]=='1'){
                    ans++;
                }
                else{
                    ans += 2;
                }
                s1[i+1] = '0';
            }
            else if(i==n-1){
                if(s1[i-1]=='1'){
                    ans++;
                }
                else{
                    ans += 2;
                }
                s1[i-1] = '0';
            }
            else{
                if(s1[i+1]=='0' and s1[i-1]=='0'){
                    ans +=2;
                }
                else{
                    if(s1[i+1]=='1'){
                        s1[i+1] = '0';
                    }
                    else{
                        s1[i-1] = '0';
                    }
                    ans++;
                }
            }
        }
        }
        for(int i=0;i<n;i++){
            if(s1[i]=='0' and s2[i]=='1')ans++;
        }
        return ans;
    }
};