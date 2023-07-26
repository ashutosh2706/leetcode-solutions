class FrontMiddleBackQueue {
public:
    deque<int> q1,q2;
    void balance() {
        while((int)q1.size() - (int)q2.size() > 1) {
            q2.push_front(q1.back());
            q1.pop_back();
        }
        while((int)q2.size() - (int)q1.size() > 1) {
            q1.push_back(q2.front());
            q2.pop_front();
        }
    }

    FrontMiddleBackQueue() {}
    
    void pushFront(int val) {
        q1.push_front(val);
        balance();
    }
    
    void pushMiddle(int val) {
        if(q1.size() > q2.size()) {
            q2.push_front(q1.back());
            q1.pop_back();
        }
        q1.push_back(val);
        balance();
    }
    
    void pushBack(int val) {
        q2.push_back(val);
        balance();
    }
    
    int popFront() {
        if(q1.empty() and q2.empty()) return -1;
        int i;
        if(q1.empty()) {
            i = q2.front();
            q2.pop_front();
        } else {
            i = q1.front();
            q1.pop_front();
        }
        balance();
        return i;
    }
    
    int popMiddle() {
        if(q1.empty() and q2.empty()) return -1;
        while(q1.size() < q2.size()) {
            q1.push_back(q2.front());
            q2.pop_front();
        }
        int i = q1.back();
        q1.pop_back();
        balance();
        return i;
    }
    
    int popBack() {
        if(q1.empty() and q2.empty()) return -1;
        int i;
        if(q2.empty()) {
            i = q1.back();
            q1.pop_back();
        }else {
            i = q2.back();
            q2.pop_back();
        }
        balance();
        return i;
    }
};