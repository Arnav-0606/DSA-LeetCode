class Solution {
public:
    string concatHex36(int n) {
        char map[36];
        for(int i=0;i<=9;i++){
            map[i] = i+'0';
        }
        for(int i=10;i<36;i++){
            map[i] = i-10 +'A';
        }
        int n1 = n*n;
        int n2 = n*n*n;
        string s1 = "";
        if(n2==0) s1 = "0";
        while(n1>0){
            s1 = map[n1%16]+s1;
            n1/=16;
        }
        string s2 = "";
        if(n2 == 0) s2 = "0";
        while(n2>0){
            s2 = map[n2%36]+s2;
            n2/=36;
        }
        return s1+s2;
    }
};