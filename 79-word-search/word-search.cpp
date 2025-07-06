class Solution {
public:
    bool f(int s,int i,int j,string word,vector<vector<char>>& board){
        bool flg = false;
        //base case
        if(s == word.size()){
            return true;
        }
        if(i<0 or i>=board.size() or j<0 or j>=board[0].size()) return false;
        if(board[i][j]!= word[s]) return false;
        char t = board[i][j];
        board[i][j] = '#';
        //recursive case
        flg = (f(s+1,i+1,j,word,board) or f(s+1,i-1,j,word,board) or f(s+1,i,j+1,word,board) or f(s+1,i,j-1,word,board));
        board[i][j] = t;
        return flg;
    }
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]==word[0]){
                    if(f(0,i,j,word,board)) return true;
                }
            }
        }
        return false;
        
    }
};