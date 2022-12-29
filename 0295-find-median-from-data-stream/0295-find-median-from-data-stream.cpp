class MedianFinder {
public:
    priority_queue<int> leftArr;
    priority_queue<int, vector<int>, greater<int>> rightArr;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        leftArr.push(num);
        rightArr.push(leftArr.top());
        leftArr.pop();
        if(leftArr.size()<rightArr.size()){
            leftArr.push(rightArr.top());
            rightArr.pop();
            
        }
    }
    
    double findMedian() {
        if(leftArr.size()==rightArr.size()) return(leftArr.top()+rightArr.top())/2.0;
        if (leftArr.size()>rightArr.size()) return leftArr.top() ;
        return  rightArr.top();
    }
};

