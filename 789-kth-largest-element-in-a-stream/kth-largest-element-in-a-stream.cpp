class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>>mH;
    KthLargest(int k, vector<int>& nums) {
        for(int i=0;i<k;i++){
            mH.push(-10e4-1);
        }
        for(int v:nums){
            if(v>mH.top()){
                mH.pop();
                mH.push(v);
            }
        }
    }
    
    int add(int val) {
        if(val>mH.top()){
            mH.pop();
            mH.push(val);
        }  
        return mH.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */