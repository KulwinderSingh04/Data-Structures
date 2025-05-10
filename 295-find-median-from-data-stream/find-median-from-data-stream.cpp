class MedianFinder {
public:
    priority_queue<int> mxHeap;
    priority_queue<int, vector<int>, greater<int>> mnHeap;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(mxHeap.size() == 0 || mxHeap.top() > num) {
            mxHeap.push(num);
        }
        else mnHeap.push(num);
        balanceHeap();
    }
    
    double findMedian() {
        if((mnHeap.size() + mxHeap.size()) % 2 == 0) {
            return (mnHeap.top() + mxHeap.top()) / 2.0;
        }
        return mxHeap.size() > mnHeap.size() ? mxHeap.top() : mnHeap.top();
    }

    void balanceHeap() {
        int mx = mxHeap.size();
        int mn = mnHeap.size();
        if(abs(mx - mn) > 1) {
            if(mx > mn) {
                mnHeap.push(mxHeap.top());
                mxHeap.pop();
            } else {
                mxHeap.push(mnHeap.top());
                mnHeap.pop();
            }
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */