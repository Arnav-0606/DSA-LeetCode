class Solution {
public:
    bool ch(char c){
        return (c>='a' and c<='z');
    }
    vector<int> countWordOccurrences(vector<string>& chunks, vector<string>& queries) {
        string s = "";
        for(string str:chunks){
            s+= str;
        }
        string word = "";
        unordered_map<string,int>mp;
        int n = s.size();
        for(int i=0;i<s.size();i++){
            if((ch(s[i])) or (s[i]=='-' and i!=0 and i!=n-1 and ch(s[i-1]) and ch(s[i+1]))){
                word += s[i];
            }
            else{
                if(word != ""){
                    mp[word]++;
                    word = "";
                }
            }
        }
        if(word != ""){
            mp[word]++;
            word = "";
        }
        vector<int>ans;
        for(int i=0;i<queries.size();i++){
            ans.push_back(mp[queries[i]]);
        }
        return ans;
    }
};