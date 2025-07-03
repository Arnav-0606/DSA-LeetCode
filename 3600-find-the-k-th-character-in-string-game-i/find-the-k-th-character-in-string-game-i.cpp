class Solution {
public:
    string transform(string str){
        string t = str;
        for(int i=0;i<t.size();i++){
            if(t[i]!='z'){
                t[i] = (char)t[i]+1;
            }
            else{
                t[i] = 'a';
            }

        }
        return str + t;
    }
    char kthCharacter(int k) {
        string start = "a";
        while(start.size()<k){
            start = transform(start);
        }
        return start[k-1];
    }
};