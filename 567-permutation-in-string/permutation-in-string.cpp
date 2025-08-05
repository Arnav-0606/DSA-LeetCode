class Solution {
public:
    bool mapCmp(int a1[],int a2[]){
        for(int i =0;i<26;i++){
            if(a1[i]!=a2[i]) return false;
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        int maps1[26]={0};
        int maps2[26]={0};
        int k = s1.size();
        int n = s2.size();
        if(k>n) return false;
        for(char c:s1){
            maps1[c-'a']++;
        }
        for(int i =0;i<k;i++){
            char ch = s2[i];
            maps2[ch-'a']++;
        }
        if(mapCmp(maps1,maps2)) return true;
        for(int i =k;i<n;i++){
            maps2[s2[i]-'a']++;
            maps2[s2[i-k]-'a']--;
            if(mapCmp(maps1,maps2)) return true;
        }
        return false;        
    }
};