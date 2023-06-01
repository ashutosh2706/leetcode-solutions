namespace user {
    string to_string(int i) {
        string res = "";
        if(i < 0) return res;
        if(i >= 0 and i <= 9) return res += (i+'0');
        return std::to_string(i);
    }
}
class Solution {
private:
string func(int n, string s, int &target) {
    if(n > target) return s;
    int len = s.length();
    string res = "";
    for(int i=0, count = 0; i<len; count = 0) {
        char c = s[i];
        while(i < len and s[i] == c) { 
            count++; 
            i++; 
        }
        res += user::to_string(count);
        res += c;
    }
    return func(n+1, res, target);
}
public:
    string countAndSay(int n) {
        if(n==1) return "1";
        return func(2,"1",n);
    }
};