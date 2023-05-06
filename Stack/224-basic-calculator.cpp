class Solution {
public:
    int calculate(string s) {
        
    string t = "";
    for(auto &c:s) if(!isspace(c)) t += c;
    stack<pair<int, int>> stk;
    int sign = 1, sum = 0;
    int i=0; 
    while(i < t.length()) {
        if(isdigit(t[i])) {
            int num = 0;
            while(i < t.length() && isdigit(t[i])) {
                num = num * 10 + (t[i] - '0');
                i++;
            }
            sum += sign * num;
            sign = 1;
        } else if(t[i] == '(') {
            stk.push({sum, sign});
            sign = 1;
            sum = 0;
            i++;
        } else if(t[i] == '-') {
            sign = -1;
            i++;
        }else if(t[i] == ')') {
            if(!stk.empty()) {
                sum = stk.top().first + (stk.top().second * sum);
                stk.pop();
            }
            i++;
        } else i++;
    }
    return sum;
    }
};

