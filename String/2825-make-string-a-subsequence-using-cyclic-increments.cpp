class Solution {
public:
    char inc(char c) {
        if(c < 'z') return (char)c+1;
        return 'a';
    }
    bool canMakeSubsequence(string str1, string str2) {
        int p2 = 0;
        for(int i=0; i<str1.length() and p2 < str2.length(); ++i) {
            
            if(str1[i] == str2[p2]) {
                p2++;
                continue;
            }
            if(inc(str1[i]) == str2[p2]) {
                p2++;
            }
            
        }
        return (p2 == str2.length());
    }
};