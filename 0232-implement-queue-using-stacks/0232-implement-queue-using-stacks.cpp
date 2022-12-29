class MyQueue {
public:
    stack<int> s1,s2;
    bool flag;
    MyQueue() {
        flag=false;
    }
    
    void push(int x) {
        s1.push(x);
    }
    
    int pop() {
          int k;
        if(!flag){
              while(!s1.empty()){
          s2.push(s1.top());
          k=s1.top();
          s1.pop();
      }  
            s2.pop();
            flag=true;
            return k;
        }
        else {
          k=s2.top();
            s2.pop();
            if(s2.size()==0) flag=false;
            return k;
        }
        return 0;
    }
    
    int peek() {
       if(s2.size()!=0) return s2.top();
        int k;
       while(!s1.empty()){
          s2.push(s1.top());
          k=s1.top();
          s1.pop();
      }  
          flag=true;
            return k;
    }
    
    bool empty() {
       if(s1.size()==0 && s2.size()==0) return true;
        return false;
    }
};
