class Solution {
public:
    string removeKdigits(string num, int k) {
    stack<char> S;
    for(int i=0; i<num.length(); i++) {
        while(!S.empty() && (S.top() > num[i]) && k) { 
            S.pop();
            k--;
        }
        S.push(num[i]);
    }
    string res;
    while(!S.empty() && k) {
        S.pop();
        k--;
    }
    while(!S.empty()) {
        res += S.top();
        S.pop();
    }
    while(res.length() && res.back() == '0') res.pop_back();
    reverse(begin(res), end(res));
    return res.length() == 0 ? "0" : res;
    }
};