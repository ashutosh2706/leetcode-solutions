class Solution {
public:
    int lengthOfLastWord(string s) {
    int n = s.length(), i = 0, ans;
    while(i < n) {
        if(s[i] == ' ') { i++; continue; }
        else {
            string ss;
            while(i < n && s[i] != ' ') ss += s[i++];
            ans = ss.length();
        }
    }
    
    return ans;

    }
};