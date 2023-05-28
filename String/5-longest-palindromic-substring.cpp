class Solution {
public:
    string longestPalindrome(string s) {
        string ans = "";
        for(int i=0; i<s.length(); i++) {
            //odd length
            int a=i, b=i;
            while(a >= 0 and b<s.length()) {
                if(s[a] == s[b]) {
                    if(b-a+1>ans.length()) ans = s.substr(a, b-a+1);
                    a--; b++;
                }
                else break; 
            }
            // even length
            a=i, b=i+1;
            while(a >=0 and b<s.length()) {
                if(s[a] == s[b]) {
                    if(b-a+1 > ans.length()) ans = s.substr(a,b-a+1);
                    a--; b++;
                }else break;
            }
        }
        return ans;
    }
};