class Solution {
public:
    string strWithout3a3b(int a, int b) {
        char A = 'a', B = 'b';
        if (b > a) {
            swap(a, b);
            swap(A, B);
        }
        string ans = "";
        while (a>0 or b>0) {
            if (a>b) {
                if (a>0) {ans+= A; a--;}
                if (a>0) {ans+= A; a--;}
            } else {
                if (a>0) {ans+= A; a--;}
            }
            if (b>0) {
                ans+= B;
                b--;
            }
        }

        return ans;
    }
};
