class Solution {
public:
    bool isPowerOfFour(int n) {
        // n = 2^x
        // -> log(n) = xlog2
        // -> log of 2 base 2 = 1
        // -> log(n) = x which should be an integer not fraction
        if(n == 1) return 1;
        if(n <= 0) return 0;
        double d = sqrt(n);
        d = log2(d);
        return (d == floor(d));

    }
};