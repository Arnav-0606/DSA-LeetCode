class Solution {
public:
bool checkCOl(vector<vector<int>>&mat,int m,int n,int row,int col){
  int msf = mat[row][col];
  for(int i = 0;i<n;i++){
    if(mat[i][col]>msf){
      msf = mat[i][col];
    }
  }
  if(msf == mat[row][col]){
    return true;
  }
  else{
    return false;
  }
}
    vector<int> luckyNumbers(vector<vector<int>>& mat) {
    int n = mat.size();
    int m = mat[0].size();
    vector<int>ans;
    int curr_row =0;
    while(curr_row<n){
    int min_in_row=0;
    for(int i=0;i<m;i++){
        if(mat[curr_row][i]<mat[curr_row][min_in_row]){
        min_in_row= i;
    }
  }
  if(checkCOl(mat,m,n,curr_row,min_in_row)){
    ans.push_back(mat[curr_row][min_in_row]);
    break;
  }
  curr_row++;
}
return ans;    
}
};