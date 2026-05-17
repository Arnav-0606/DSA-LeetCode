class MedianFinder {
public:
    priority_queue<int> l;
    priority_queue<int, vector<int>, greater<int>> r;
    double med;

    MedianFinder() {
    }
    
    void addNum(int num) {
        if(l.empty()){
            l.push(num);
            return;
        }
        med = findMedian();
        if(num<=med){
            if(l.size()==r.size()){
                l.push(num);
            }
            else{
                l.push(num);
                r.push(l.top());
                l.pop();
            }

        }
        else{
            if(l.size()==r.size()){
                r.push(num);
                l.push(r.top());
                r.pop();
            }
            else{
                r.push(num);
            }
        }
   
    }
    
    double findMedian() {
        if(l.size()==r.size()){
            return ((l.top()+r.top())/2.0);
        }
        else{
            return l.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */