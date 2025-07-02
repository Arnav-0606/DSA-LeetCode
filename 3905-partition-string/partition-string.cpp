class Solution {
public:
    vector<string> partitionString(string str) {
        set<string>s;
        vector<string>ans;
        int i =0;
        int j =0;
        while(j<str.size()){
            string t = str.substr(i,j-i+1);
            if(s.find(t)==s.end()){
                s.insert(t);
                ans.push_back(t);
                j++;
                i=j;
            }
            else{
                j++;
            }
        }
        return ans;
    }
};