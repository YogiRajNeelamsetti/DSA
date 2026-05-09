class MedianFinder {
public:
    priority_queue<int> small;
    priority_queue<int, vector<int>, greater<int>> large;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(!large.empty() && num > large.top()) {
            large.push(num);
        } else {
            small.push(num);
        }

        if(small.size() > large.size()) {
            int t = small.top();
            small.pop();
            large.push(t);
        } else if(large.size() > small.size()) {
            int t = large.top();
            large.pop();
            small.push(t);
        }
    }
    
    double findMedian() {
        double median;
        if(small.size() > large.size()) {
            median = small.top();
        } else if(large.size() > small.size()) {
            median = large.top();
        } else {
            median = (small.top() + large.top()) / 2.0;
        }
        return median;
    }

};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */