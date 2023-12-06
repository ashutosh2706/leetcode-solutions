class Solution {
public:
    typedef long long int ll;
    bool judgeSquareSum(int c) {
        if(c == 0) return 1;
        ll x = floor((double)sqrt(c));
        for(ll i=1; i<=x; ++i) {
            ll r = c - (i*i);
            ll l = sqrt(r);
            if(l*l == r) return 1;
        }
        return 0;
    }
};
