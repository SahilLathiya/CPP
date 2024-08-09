class MyStack {
public:
    queue<int> q1;
    queue<int> q2;
    int qNo = 1;
    MyStack() {
   
    }
    
    void push(int x) {
        if(qNo==1)
            q1.push(x);
        else
            q2.push(x);
    }
    
    int pop() {
        if(qNo==1){
            while(q1.size()>1){
                q2.push(q1.front());
                q1.pop();
            }
            qNo = 2;
            int x = q1.front();
            q1.pop();
            return x;
        }
        while(q2.size()>1){
                q1.push(q2.front());
                q2.pop();
            }
            qNo = 1;
            int x = q2.front();
            q2.pop();
            return x;
    }
    
    int top() {
        int x;
        if(qNo==1){
            while(q1.size()>0){
                x = q1.front();
                q2.push(x);
                q1.pop();
            }
            qNo = 2;
            return x;
        }
        while(q2.size()>0){
                x = q2.front();
                q1.push(x);
                q2.pop();
            }
            qNo = 1;
            return x;
    }
    
    bool empty() {
        return (q1.size()==0 && q2.size()==0);
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