class Solution {
public:
    string reverseWords(string str) {
        stack<string>s;
        string temp ="";
        int i =0;
        int n = str.length();
        while(i<n){
            while(str[i] == ' ' and i<n) i++;

            temp ="";
            while(str[i] != ' ' and i<n){
                temp += str[i];
                i++;
            }
            if(!temp.empty())s.push(temp);
        }
        string ans = s.top();
        s.pop();
        while(!s.empty()){
            ans+=' ';
            ans += s.top();
            s.pop();
        }    
        return ans; 
    }
};