class Solution {
public:
    bool isPalindrome(int x) {
        string s = to_string(x), t;
        t = s;
        std::reverse(begin(s),end(s));
        return s==t;
    }
};