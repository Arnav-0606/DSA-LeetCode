class Solution {
public:
    bool compare(vector<int>&a,vector<int>&b){
        for(int i =0;i<26;i++){
            if(a[i]!=b[i]) return false;
        }
        return true;

    }
    vector<int> findAnagrams(string s, string p) {
        int n = s.size();
        int k = p.size();
        vector<int>ans;
        if(n<k) return ans;
        vector<int>a(26,0);
        for(int i=0;i<k;i++){
            a[p[i]-'a']++;
        }
        vector<int>b(26,0);
        int i =0;
        int j =0;
        while(j<k){
            b[s[j]-'a']++;
            j++;
        }
        if (compare(a, b)) ans.push_back(0);
        while(j<n){
            b[s[i]-'a']--;
            i++;
            b[s[j]-'a']++;
            if(compare(a,b)) ans.push_back(i);
            j++;
        }
        return ans;
    }
};