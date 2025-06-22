class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string>ans;
        int i = 0;
        int j =0;
        string temp;
        while(i<s.size()){
            temp ="";
            while(i<s.size() and j<k){
                temp+= s[i];
                j++;
                i++;
            }
            if(j==k){
                j=0;
                ans.push_back(temp);
            }
        }
        if(j!=0){
        while(j<k){
            temp+= fill;
            j++;
            };
        ans.push_back(temp);
        }
        return ans;
    }
};