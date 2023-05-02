class MinStack {
public:
    map<int, int> map;
    stack<int> S;
    MinStack() {}
    
    void push(int val) {
        S.push(val);
        map[val]++;
    }
    
    void pop() {
        int e = S.top();
        S.pop();
        if(map[e] == 1) map.erase(e);
        else map[e]--;
    }
    
    int top() {
        return S.top();
    }
    
    int getMin() {
        return map.begin()->first;
    }
};