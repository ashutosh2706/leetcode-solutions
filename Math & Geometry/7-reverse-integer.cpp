class Solution {
public:
    int reverse(int x) {
        string s = to_string(x);
        ::reverse(begin(s), end(s));
        long l = stol(s);
        if(l >= INT_MIN and l<= INT_MAX) {
            return (x < 0) ? -l : l;
        }
        return 0;
    }
};