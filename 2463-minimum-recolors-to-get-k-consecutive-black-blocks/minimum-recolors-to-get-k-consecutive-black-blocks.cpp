class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int wb =0;
        for(int i=0;i<k;i++){
            if(blocks[i]=='W') wb++;
        }
        int ans = wb;
        for(int i=k;i<blocks.size();i++){
            if(blocks[i]=='W') wb++;
            if(blocks[i-k]=='W')wb--;
            ans = min(ans,wb);
        }
        return ans;
        
    }
};