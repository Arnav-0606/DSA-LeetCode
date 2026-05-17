class MedianFinder {
public:
    priority_queue<int> l;
    priority_queue<int, vector<int>, greater<int>> r;
    double med;

    MedianFinder() {
        med = INT_MAX;   
    }
    
    void addNum(int num) {
        med = findMedian();
        if(med==INT_MAX){
            l.push(num);
            med = num;
            return;                        
        }
        if(num<=med){
            if(l.size()==r.size()){
                l.push(num);
                med = l.top();
            }
            else{
                l.push(num);
                r.push(l.top());
                l.pop();
                med = (l.top()+r.top())/2.0;
            }

        }
        else{
            if(l.size()==r.size()){
                r.push(num);
                l.push(r.top());
                r.pop();
                med = l.top();
            }
            else{
                r.push(num);
                med = (l.top()+r.top())/2.0;
            }
        }
    }
    
    double findMedian() {
        return med;
        
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */