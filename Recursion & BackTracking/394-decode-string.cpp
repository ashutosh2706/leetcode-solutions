class Solution {
private:
string f(string &s, int &i) {

    string res;
    while(i < s.length() && s[i] != ']') {
        if(!isdigit(s[i])) res+=s[i++];
        else {
            int n = 0;
            while(i < s.length() && isdigit(s[i])) 
            n = n*10 + (s[i++] - '0');
            i+=1; // '['
            string t = f(s, i);
            i+=1; // ']'

            while(n--) res += t;
        }
    }
    return  res;
}
public:
    string decodeString(string s) {
        int i = 0;
        return f(s, i);
    }
};