class Solution {
public:
    string convertToTitle(int n) {
        string res;
        while(n > 0) {
            n--;
            res += (char)((n % 26) + 'A');
            n /= 26;
        }
        reverse(begin(res), end(res));
        return res;
    }
};