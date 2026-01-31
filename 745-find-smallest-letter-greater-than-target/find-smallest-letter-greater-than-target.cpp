class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        char ans = letters[0];
        int n = letters.size();
        for(int i=n-1;i>=0;i--){
            if(letters[i]<=target){
                return ans;     
            }
            else{
                ans = letters[i];
            }
        }
        return ans;
    }
};