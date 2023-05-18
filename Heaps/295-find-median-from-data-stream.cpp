#include<cstdlib>
class MedianFinder {
public:

    priority_queue<int, vector<int>, greater<int>> min_heap;
    priority_queue<int> max_heap;
    
    MedianFinder() {}
    
    void addNum(int num) {
        if(max_heap.empty() || num < max_heap.top()) {
            max_heap.push(num);
        } else min_heap.push(num);

        while(abs((int)max_heap.size() - (int)min_heap.size()) > 1) {
            if(min_heap.size() > max_heap.size()) {
                max_heap.push(min_heap.top());
                min_heap.pop();
            }
            else if(min_heap.size() < max_heap.size()) {
                min_heap.push(max_heap.top());
                max_heap.pop();
            }
        }
    }
    
    double findMedian() {
        
        if(max_heap.size() == min_heap.size()) return max_heap.size() == 0 ? 0 : (double)(max_heap.top() + min_heap.top())/2.0; 
        else return max_heap.size() > min_heap.size() ? max_heap.top() : min_heap.top();
    }
};