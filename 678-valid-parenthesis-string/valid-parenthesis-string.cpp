class Solution {
public:
    bool checkValidString(string s) {
        int oc =0;
        int cc =0;
        for(int i =0;i<s.size();i++){
            if(s[i]=='(' or s[i]=='*'){
                oc++;
            }
            else{
                oc--;
            }
            if(oc<0) return false;
        }
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]==')' or s[i]=='*'){
                cc++;
            }
            else{
                cc--;
            }
            if(cc<0) return false;
        }
        return true;
    }
};