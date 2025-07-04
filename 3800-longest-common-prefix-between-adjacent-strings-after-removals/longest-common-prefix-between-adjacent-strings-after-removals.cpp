class Solution {
public:
    int findLcs(string a,string b){
        int ans =0;
        int i =0;
        int j =0;
        while(a[i] !='\0' and b[j]!='\0' and a[i]==b[j]){
            ans++;
            i++;
            j++;
        }
        return ans;
    }
    vector<int> longestCommonPrefix(vector<string>& words) {
        int n = words.size();
        if(n==0) return {};
        if(n==1) return {0};
        vector<int> ans(n);
        vector<int>prefix_lcs(n);
        vector<int>suffix_lcs(n);
        prefix_lcs[0] =0;
        suffix_lcs[n-1] =0;
        for(int i=1;i<words.size();i++){
            prefix_lcs[i] = max(prefix_lcs[i-1],findLcs(words[i],words[i-1]));
        }
        for(int i =n-2;i>=0;i--){
            suffix_lcs[i] = max(suffix_lcs[i+1],findLcs(words[i],words[i+1]));
        }
        ans[0] = suffix_lcs[1];
        ans[n-1] = prefix_lcs[n-2];
        for(int i=1;i<n-1;i++){
            ans[i] = max(prefix_lcs[i-1],max(suffix_lcs[i+1],findLcs(words[i-1],words[i+1])));
        }
        return ans;        
    }
};