class MinStack {
public:
    int arr[100000];
    vector<int> minsofar;
    int topElement;
    MinStack() {
        topElement = -1;
    }
    void push(int val) {
        if(topElement == -1){
            topElement++;
            arr[topElement] = val;
            minsofar.push_back(val); 
        }
        else{
            int newMinimum = min(minsofar.back(), val);
            topElement++;
            arr[topElement] = val;
            minsofar.push_back(newMinimum);
        } 
    }
    void pop() {
        topElement--;
        minsofar.pop_back();
    }
    int top() {
        return arr[topElement];
    }
    int getMin() {
        return minsofar.back();
    }
};