class Solution {
public:
    int calculate(string s) {
        auto prec = [](char c) {
            if(c == '+' or c == '-') return 0;
            return 1;
        };
        string t = "";
        for(int i=0; i<s.length(); i++) if(!isspace(s[i])) t += s[i];
        stack<int> nums;
        stack<char> op;
        int i = 0, n = t.length();
        while(i < n) {
            if(isdigit(t[i])) {
                int num = 0;
                while(i < n and isdigit(t[i])) {
                    num = num * 10 + (t[i] - '0');
                    i++;
                }
                nums.push(num);
            } else {
                while(!op.empty() and (prec(t[i]) <=  prec(op.top()))) {
                    int e1 = nums.top(); nums.pop();
                    int e2 = nums.top(); nums.pop();
                    char ch = op.top(); op.pop();
                    if(ch == '+') nums.push(e1 + e2);
                    else if(ch == '-') nums.push(e2 - e1);
                    else if(ch == '*') nums.push(e1 * e2);
                    else nums.push(floor(e2 / e1));

                }
                op.push(t[i++]);
            }
        }
        while(!op.empty() and nums.size() > 1) {
            int e1 = nums.top(); nums.pop();
            int e2 = nums.top(); nums.pop();
            char ch = op.top(); op.pop();
            if(ch == '+') nums.push(e1 + e2);
            else if(ch == '-') nums.push(e2 - e1);
            else if(ch == '*') nums.push(e1 * e2);
            else nums.push(floor(e2 / e1));            
        }

        return nums.top();

    }
};
