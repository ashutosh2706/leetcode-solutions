class Solution {
private:
vector<string> res;
void form(int open, int close, string &s, int &n) {
    if(s.length() == 2 * n) {
        res.push_back(s);
        return;
    }
    if(open < n) {
         s.push_back('(');
         form(open+1, close, s, n);
         s.pop_back();
    }
    if(close < open) {
        s.push_back(')');
        form(open, close+1, s, n);
        s.pop_back();
    }

}
public:
    vector<string> generateParenthesis(int n) {
        string s = "";
        form(0,0,s,n);
        return res;
    }
};