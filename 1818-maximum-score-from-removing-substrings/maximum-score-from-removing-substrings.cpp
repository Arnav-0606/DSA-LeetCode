class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int ans =0;
        string p1 = "ab";
        string p2 = "ba";
        if(y>x){
            swap(p1,p2);
            swap(x,y);
        }
        stack<char>stk;
        stk.push(s[0]);
        for(int i=1;i<s.size();i++){
            if(!stk.empty() and stk.top()==p1[0] and s[i]==p1[1]){
                ans += x;
                stk.pop();
            }
            else{
                stk.push(s[i]);
            }
        }
        string s1 ="";
        while(!stk.empty()){
            s1 += stk.top();
            stk.pop();
        }
        reverse(s1.begin(),s1.end());
        stk.push(s1[0]);
        for(int i=1;i<s1.size();i++){
            if(!stk.empty() and stk.top()==p2[0] and s1[i]==p2[1]){
                ans += y;
                stk.pop();
            }
            else{
                stk.push(s1[i]);
            }
        }
        return ans;
    }
};