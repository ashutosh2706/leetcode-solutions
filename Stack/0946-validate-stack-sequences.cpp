class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
    
    stack<int> s;    
    int i = 0, j = 0;
    s.push(pushed[i++]);
    while(i < pushed.size() || !s.empty()) {

        if(!s.empty() && s.top() == popped[j]) {
            s.pop();
            j++;
        } else {
            if(i < pushed.size()) s.push(pushed[i++]);
            else break;
        }
    }

    return s.empty();
    }
};