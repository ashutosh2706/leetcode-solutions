class Solution {
public:
    int numSub(string s) {
        int l=0, r=0, n = s.size(), ans = 0, mod = 1e9+7;
        while(r < n) {
            if(s[l] == s[r]) ++r;
            else {
                if(s[l] == '1') {
                    long long d = r-l, ss;
                    ss = (d*(d+1))/2;
                    ans = (ans + (ss%mod))%mod;
                }
                l = r;
            }
        }
        if(s[l] == '1') {
            long long d = r-l, ss;
            ss = (d*(d+1))/2;
            ans = (ans + (ss%mod))%mod;
        }
        return ans;
    }
};