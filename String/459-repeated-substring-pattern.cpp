class Solution {
public:
    bool check(string &ss, string &str) {
    int l = ss.length(), n = str.length();
    for(int i=l; i<n; i+=l) {
        if(str.substr(i, l) != ss) return 0;
    }
    return 1;
}
    bool repeatedSubstringPattern(string &str) {
    for(int i=1; i<str.length(); i++) {
        string ss = str.substr(0,i);
        if(check(ss,str) == 1) {
            return 1;
        }
    }
    return 0;
    }
};