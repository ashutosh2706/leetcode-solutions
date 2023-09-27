class Solution {
public:
    int countHomogenous(string s) {
        int l = 0, r = 0, n = s.size(), ans = 0, mod = 1e9+7;
        while(r < n) {
            if(s[l]==s[r])  ++r;
            else {
                long long d = r-l;
                long long ss = (d*(d+1))/2;
                ans = (ans + (ss % mod)) % mod;
                l = r;
            }
        }       
        long long d = r-l;
        long long ss = (d*(d+1))/2;
        return (ans + (ss % mod)) % mod;
    }
};

