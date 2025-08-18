class Solution {
public:
    int getSum(int a, int b) {
        int ans =0;
        int carry =0;
        for(int i =0;i<32;i++){
            int x = (a>>i)&1;
            int y = (b>>i)&1;
            if(x == 1 and y ==1){
                if(carry ==0){
                    carry =1;
                }
                else{
                    ans |= (1<<i);
                }
            }
            else if ((x==1 and y==0) or (x==0 and y ==1)){
                if(carry ==0 ){
                    ans |= (1<<i);
                }
                else{
                    carry =1;
                }
            }
            else{
                if(carry ==1){
                    carry =0;
                    ans |= (1<<i);
                }
            }
        }   
        return ans;
    }
};