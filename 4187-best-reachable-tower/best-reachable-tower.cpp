class Solution {
public:
    bool checkReachable(vector<int>tower,int x,int y,int r){
        int a = tower[0];
        int b = tower[1];
        if(abs(x-a)+abs(y-b)<=r) return true;
        return false;
    }
    vector<int> bestTower(vector<vector<int>>& towers, vector<int>& center, int radius) {
        int qf = -1;
        vector<int>ans(2,-1);
        int n = towers.size();
        for(int i=0;i<n;i++){
            if(checkReachable(towers[i],center[0],center[1],radius)){
                if(towers[i][2]==qf){
                    if(towers[i][0]== ans[0]){
                        if(towers[i][1]<ans[1]){
                            ans[0] = towers[i][0];
                            ans[1] = towers[i][1];
                            qf = towers[i][2];   
                        }
                    }
                    else if(towers[i][0] < ans[0]){
                        ans[0] = towers[i][0];
                        ans[1] = towers[i][1];
                        qf = towers[i][2];               
                    }                                   
                }
                else if(towers[i][2]>qf){
                    ans[0] = towers[i][0];
                    ans[1] = towers[i][1];
                    qf = towers[i][2];
                }
            }
        }
        return ans;
        
    }
};