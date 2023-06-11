class Solution {
public:
    string smallestString(string s) {
        int i = 0;
        while(i < s.length() and s[i] == 'a') {
            if(i == s.length() - 1) s[i] = 'z';
            i++;
        }

        for(; i<s.length(); i++) {
            if(s[i] == 'a') break;
            else s[i] -= 1;
        }
        return s;
    }
};