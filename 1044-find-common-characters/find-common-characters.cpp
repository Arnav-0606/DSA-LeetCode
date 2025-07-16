class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<string>ans;
        int n = words.size();
        int old[26] ={0};
        for(char c : words[0]){
            old[c-'a']++;
        }
        for(int i =1;i<n;i++){
            int ne[26]={0};
            for(char c:words[i]){
                ne[c-'a']++;
            }
            for(int i=0;i<26;i++){
                old[i] = min(old[i],ne[i]);
            }
        }
        for(int i=0;i<26;i++){
            while(old[i]--){
                char ch = (char)('a'+i);
                 ans.push_back(string(1, ch));
            }
        }
        return ans;
    }
};