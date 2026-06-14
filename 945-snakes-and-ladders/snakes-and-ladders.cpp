class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        int k =0;
        unordered_map<int,int>mp;
        for(int i=n-1;i>=0;i--){
            if((n-i+1)&1){
                for(int j=n-1;j>=0;j--){
                    k++;
                    if(board[i][j]!=-1){
                        mp[k] = board[i][j];
                    }
                }
            }
            else{
                for(int j=0;j<n;j++){
                    k++;
                    if(board[i][j]!=-1){
                        mp[k] = board[i][j];
                    }
                }
            }
        }
        int d = n*n;
        vector<bool>vis(d+1,false);
        queue<int>q;
        vis[1] = true;
        q.push(1);
        q.push(-1);
        int l = 0;
        while(!q.empty()){
            int t = q.front();
            q.pop();
            if(t==d){
                return l;
            }
            if(t==-1){
                l++;
                if(!q.empty())q.push(-1);
                continue;
            }
            for(int i=1;i<=6;i++){
                int v = min(i+t,d);
                if(mp.count(v)){
                    if(vis[mp[v]]) continue;
                    q.push(mp[v]);
                    vis[mp[v]]=true;
                }
                else{
                    if(vis[v]) continue;
                    q.push(v);
                    vis[v]=true;
                }
            }
        }
        return -1;
        
    }
};