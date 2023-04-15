class Solution {
public:
    bool isSubsequence(string s, string t) {

    int n = t.length(), p = 0;
    for(int i=0; i<n; i++) {
        if(p == s.length()) return 1;
        if(s[p] == t[i]) p++;
    }
    return p == s.length();
    
    }
};