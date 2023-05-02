class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        
        stack<string> S;
        for(string &s : tokens) {
            int e1,e2;
            if(s == "+") {
                e1 = stoi(S.top()); S.pop();
                e2 = stoi(S.top()); S.pop();
                S.push(to_string(e1 + e2));
            
            }else if(s == "-") {
                e1 = stoi(S.top()); S.pop();
                e2 = stoi(S.top()); S.pop();
                S.push(to_string(e2 - e1));

            }else if(s == "*") {
                e1 = stoi(S.top()); S.pop();
                e2 = stoi(S.top()); S.pop();
                S.push(to_string(e1 * e2));
            
            }else if(s == "/") {
                e1 = stoi(S.top()); S.pop();
                e2 = stoi(S.top()); S.pop();
                S.push(to_string((int)(e2 / e1)));
            
            }else S.push(s);
        }
        return stoi(S.top());
    }
};