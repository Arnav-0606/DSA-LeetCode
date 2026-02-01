class Solution {
public:
    int countMonobit(int n) {
        return 1+log2(n+1);
    }
};