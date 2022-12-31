class MinStack {
public:
    stack<int> st;
    vector<int> minsofar;
    int mini;
    MinStack() {
        mini=INT_MAX;
    }
    
    void push(int val) {
        if(minsofar.size()==0) minsofar.push_back(val);
        else minsofar.push_back(min(minsofar.back(),val));
        st.push(val);
    }
    
    void pop() {
        minsofar.pop_back();
       st.pop(); 
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minsofar.back();
    }
};
