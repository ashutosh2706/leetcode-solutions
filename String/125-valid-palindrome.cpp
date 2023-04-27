class Solution {
public:
    bool isPalindrome(string s) {
        
    string ss = "";
    for(auto &c : s) {
        if(c >= 'A' && c <='Z') c += 32;
        if((c >= 'a' && c <= 'z') || (c>='0' && c <='9')) ss+=c;
    }
    string t = ss;
    reverse(begin(ss), end(ss));
    return ss == t;

    }
};