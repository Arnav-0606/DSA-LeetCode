class MyStack {
public:
    queue<int>q1;
    int topint;
    MyStack() {   
    }
    void push(int x) {
        topint = x;
        q1.push(x);       
    }
    int pop() {
        int n = q1.size();
        for(int i =1;i<n;i++){
            topint = q1.front();
            q1.push(q1.front());
            q1.pop();
        }
        int t = q1.front();
        q1.pop();
        return t;

    }
    int top() {
        return topint;
    }
    bool empty() {
        return q1.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */