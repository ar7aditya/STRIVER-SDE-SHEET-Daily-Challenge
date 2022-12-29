class MyStack {
public:
    int temp;
    queue<int> q1;
    MyStack() {
        temp=0;
    }
    
    void push(int x) {
        int t1=temp; 
            q1.push(x);
            while(t1){
                q1.push(q1.front());
                q1.pop();
                t1--;
            }
            temp=temp+1;
    }
    
    int pop() {
        int t1=q1.front();
            q1.pop();
            return t1;
    }
    
    int top() {
        return q1.front();
    }
    
    bool empty() {
        return q1.empty();
    }
};
