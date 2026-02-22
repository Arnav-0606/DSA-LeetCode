class Solution {
public:
    int scoreDifference(vector<int>& nums) {
        int s1 = 0;
        int s2 = 0;
        bool p1=1,p2=0;
        for(int i=0;i<nums.size();i++){
            if((nums[i]&1)){
                swap(p1,p2);                
            }
            if(i%6==5){
                swap(p1,p2);
            }
            if(p1){
                s1+=nums[i];
            }
            else{
                s2+= nums[i];
            }
        }
        return s1-s2;
    }
};