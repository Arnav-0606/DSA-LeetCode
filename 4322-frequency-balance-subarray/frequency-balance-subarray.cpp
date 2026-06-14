class Solution {
public:
    int getLength(vector<int>& nums) {
        int n = nums.size();
        int ans = 1;
        for(int i=0;i<n;i++){
            unordered_map<int,int>mp,fmp;
            for(int j =i;j<n;j++){
                mp[nums[j]]++;
                int f = mp[nums[j]];
                if(f!=1){
                    fmp[f-1]--;
                    if(fmp[f-1]==0){
                        fmp.erase(f-1);
                    }
                }
                fmp[f]++;
                int a=0,b=0;
                if(mp.size()==1) ans = max(ans,j-i+1);
                if(fmp.size()==2){
                for(auto [ke,v] :fmp){
                   swap(a,b);
                   a = ke;
                }
                if(a==2*b or b==2*a) ans = max(ans,j-i+1);
            }
            }
        }
        return ans;
        
    }
};