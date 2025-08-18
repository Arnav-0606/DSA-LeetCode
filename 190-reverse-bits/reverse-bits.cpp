class Solution {
public:
    int reverseBits(int n) {
        unsigned int ans =0;
        for(int i =0;i<32;i++){
            if((n>>i)&1){
                ans |= (1U<<(31-i));
            }
        }
        return ans;
        
    }
};